import torch
import torch.nn as nn
import torch.nn.functional as F
import torch.optim as optim
from torch.autograd import Variable
import numpy as np
import sys
import os
from torchvision import transforms, utils
from glob import glob
import time
import cv2
import matplotlib.pyplot as plt
from matplotlib.backends.backend_agg import FigureCanvasAgg as FigureCanvas
from matplotlib.figure import Figure
from torch.distributions.multivariate_normal import MultivariateNormal
from model.server_path import server_root_path
import time
from tqdm import tqdm
from torch.utils.data import DataLoader
from tensorboardX import SummaryWriter
import pdb
from sklearn.preprocessing import StandardScaler
from scipy.stats import norm
from scipy.interpolate import make_interp_spline, BSpline
from skimage import io
from torchvision.transforms import ToTensor

import model.config_supervised as config_supervised
import model.train_val_utils as util
from model.data_loader import TemplateDataset
from classifiers.BaseClassifier import BaseClassifier
from typing import Tuple, List, Union, Dict, Counter
from util import ProcessedFolder, ProcessedSnapshotFolder
from classifiers.NNClassifier import NNClassifier
from classifiers.config import Config
from model.get_vec import CodeToVec
from model.CodeVectorizer import CodeVectorizer
        
project_folder_source="/home/user/data/project5/nn_DA/processed/gcj_java/gcj2016/java/"
project_folder_negative="/home/user/data/project5/nn_DA/processed/gcj_java/gcj_negative/java/"

vectorization=CodeVectorizer(50000, 50000, 256)

i=0
i_tar=0
j=0
class TrainerG(NNClassifier):

    def __init__(self, config: Config, model,project_folder: ProcessedFolder, min_max_count: Tuple[int, int], 
                    network, optimizer, exp_name, settings,change_entities=None,change_to_time_bucket=None,author_occurrences=None,
                 context_splits=None):
        super(TrainerG, self).__init__(config, project_folder, min_max_count, 
                change_entities, change_to_time_bucket, author_occurrences, context_splits)
        print('function __init__')
        self.to_train = settings['to_train']

        # Optimizers to use
        self.optimizer = optimizer
        self.which_optimizer = list(sorted(self.optimizer.keys()))
        print('\noptimizers: ' + str(self.which_optimizer) + '\n')

        # Save the settings
        self.settings = settings

        # Initialize the val and train writers
        self.val_writer = SummaryWriter(os.path.join(server_root_path, 'summaries', exp_name, 'logdir_val'))
        self.train_writer = SummaryWriter(os.path.join(server_root_path, 'summaries', exp_name, 'logdir_train'))
        
        # Extract commonly used settings
        self.batch_size = settings['batch_size']
        self.current_iteration = settings['start_iter']

        # Get the index lists
        self.Cs = settings['C'] + settings['Cs_dash']

        # Get number of classes
        self.num_C = settings['num_C']
        self.num_Cs_dash = settings['num_Cs_dash']
        self.num_Ct_dash = settings['num_Ct_dash']
        self.num_Cs = settings['num_Cs']
        self.num_Ct = settings['num_Ct']

        # Initialize data loaders
        #self.get_all_dataloaders()
        self.__sample_loaders()
        self.get_val_set(model)
        self.mu_sigma = None
        self.mu_sigma_distribution = None

        # Mu Sigma is calculated at each validation iteration. For the first iteration, no mu sigmas exist, so don't load unless start iteration is higher.
        if (self.current_iteration >= self.settings['val_after']):

            self.recalculate_mu_sigma(model)


    def get_mu_sigma_threshold(self, mu_sigma, mu_sigma_distro, maximum=True):

        MU, COV = torch.from_numpy(mu_sigma[0]).cuda(), torch.from_numpy(mu_sigma[1]).cuda()
        u,s,v = torch.svd(COV)
        if maximum:
            eigen_direction = v[:, 0]
        else:
	        eigen_direction = torch.matmul(v, torch.sqrt(s))

        threshvec = MU + 3 * eigen_direction
        return mu_sigma_distro.log_prob(threshvec)


    def get_histogram(self, features, bin_size=0.01, normalize=True):
        print('function get_histogram')

        F = [int(float(f)/bin_size) for f in features]
        D = {}
        for f in F:
            if f in D: D[f] += 1
            else: D[f] = 1
        x = np.array([float(k*bin_size) for k in sorted(D.keys())])
        y = np.array([float(D[f]) for f in sorted(D.keys())])

        if normalize:
            y = y / np.sum(y)

        return x, y

    def __sample_loaders(self, fold_ind: Union[int, Tuple[int, int]] = 0) -> Tuple[DataLoader, DataLoader]:
        print("Load negative samples")
        self.loader_train_negative,self.loader_source_val, self.original_negative_labels = NNClassifier.tmp_loder(self,path=project_folder_negative)
        print(self.original_negative_labels)
        print("Load source domain samples")
        self.loader_train, self.loader_source_val,self.original_source_labels = NNClassifier.tmp_loder(self,path=project_folder_source)
        print(self.original_source_labels)

    def repair_Cs_labels(self,Cs,Cs_labels,Cs_lable_id):
        result = []
        for i in Cs_lable_id:
            result.append(Cs.index(Cs_labels[i]))
        result = torch.LongTensor(result)
        return result
    
    def get_all_dataloaders(self):
        print('function get_all_dataloaders')
        
        dataset_train = TemplateDataset(self.index_list_train_source, transform=transforms.Compose([transforms.ToTensor()]), random_choice=False)
        self.loader_train = DataLoader(dataset_train, batch_size=self.batch_size, shuffle=True, num_workers=2)

        dataset_source_val = TemplateDataset(self.index_list_val_source, transform=transforms.Compose([transforms.ToTensor()]), random_choice=False)
        self.loader_source_val = DataLoader(dataset_source_val, batch_size=self.batch_size, shuffle=True, num_workers=2)

        dataset_source_train_negative = TemplateDataset(self.index_list_train_negative, transform=transforms.Compose([transforms.ToTensor()]), random_choice=False)
        self.loader_train_negative = DataLoader(dataset_source_train_negative, batch_size=self.batch_size, shuffle=True, num_workers=2)


    def get_loss(self, which_loss):
        print('function get_loss')
        
        if which_loss == 'classification':
            outs = torch.cat([self.features['Cs'], self.features['Cn']], dim=-1)
            # outs = self.features['Cs']

            topK = self.settings['num_positive_samples']
            positive_sample_loss = nn.CrossEntropyLoss(reduction='mean')(outs[:topK], self.gt[:topK].long())
            negative_sample_loss = nn.CrossEntropyLoss(reduction='mean')(outs[topK:], self.gt[topK:].long())
            w1, w2 = self.settings['classification_weight']
            loss = w1 * positive_sample_loss + w2 * negative_sample_loss
        elif which_loss == 'pos_sam_recon':
            topK = self.settings['num_positive_samples']
            loss = torch.mean( torch.sum(torch.pow(self.features['M'][:topK] - self.features['G'][:topK], 2), dim=-1) )


        elif which_loss == 'pos_sample_recon':
            topK = self.settings['num_positive_samples']

            loss = torch.mean( torch.sum( torch.pow(self.features['Fs_sample'][:topK] - self.features['Fs_sample_recon'][:topK], 2), dim=-1 ) )


        elif which_loss == 'logsoftmax': # Increase the class confidence by decreasing the distance
            # This is L_p defined in the paper. While implementing in PyTorch, we decrease the distance to the corresponding cluster,
            # which has the same effect as increasing the relative posterior confidence.
            topK = self.settings['num_positive_samples']
            malhanobis_squared_mat = torch.zeros((topK, self.num_C + self.num_Cs_dash)).cuda()
            for c in range(self.num_C + self.num_Cs_dash):
                mu = torch.from_numpy(self.mu_sigma[str(c)][0]).cuda()
                #print("mu",mu)
                malhanobis_squared_distance = (self.mu_sigma_distribution[str(c)].log_prob(mu) - self.mu_sigma_distribution[str(c)].log_prob(self.features['Fs'][:topK])) ** 2
                malhanobis_squared_mat[:, c] = malhanobis_squared_distance
            #print("malhanobis_squared_mat",malhanobis_squared_mat.shape)
            norm_malhanobis_mat = malhanobis_squared_mat / torch.sum(malhanobis_squared_mat, dim=-1, keepdim=True)
            corr_conf = torch.zeros((self.settings['batch_size'],)).cuda()
            for i in range(self.settings['batch_size']):
                corr_conf[i] = norm_malhanobis_mat[i, self.gt[i]]
            loss = torch.mean( torch.log(corr_conf), dim=0 )
            # print("corr_conf",corr_conf.shape)
            # print("norm_malhanobis_mat",norm_malhanobis_mat.shape)

        else:
            raise NotImplementedError('Not implemented loss function ' + str(which_loss))
        #print("self.gtself.gt",self.gt)
        #print("loss.shape",loss.shape)
        self.summary_dict['loss/' + str(which_loss)] = loss.data.cpu().numpy()
        return loss


    def recalculate_mu_sigma(self,model):
        # print('function recalculate_mu_sigma')
        print('\nRecalculating mu sigma\n')
        self.mu_sigma = self.get_mu_sigma(model)
        self.mu_sigma_distribution = {}

        for key in self.mu_sigma:
            mu, sigma = torch.from_numpy(self.mu_sigma[key][0]).cuda(), torch.from_numpy(self.mu_sigma[key][1]).cuda()
            self.mu_sigma_distribution[key] = torch.distributions.MultivariateNormal(mu, sigma)

        self.mu_sigma_threshold = []
        for key in range(self.num_C + self.num_Cs_dash):
            self.mu_sigma_threshold.append( self.get_mu_sigma_threshold(self.mu_sigma[str(key)], self.mu_sigma_distribution[str(key)]) )
        # print(self.mu_sigma_threshold)
        self.mu_sigma_threshold = torch.FloatTensor(self.mu_sigma_threshold).view((1, self.num_C + self.num_Cs_dash)).cuda()


    def loss(self):

        concat_outputs_sam = torch.cat([self.features['Cs'], self.features['Cn']], dim=-1)
        concat_softmax_sam = F.softmax(concat_outputs_sam/self.settings['softmax_temperature'], dim=-1)
        pred_classes_sam = torch.argmax(concat_softmax_sam, dim=-1) 
        pos = self.pos_num

        pred_classes_pos_sam = pred_classes_sam[:pos] 
        gt_classes_pos_sam = self.gt[:pos] 
        
        if len(pred_classes_pos_sam) != 0:
            source_acc_pos_sam = (pred_classes_pos_sam.float() == gt_classes_pos_sam.float()).float().mean()#计算准确度
            self.summary_dict['acc/source_acc_pos_sam'] = source_acc_pos_sam

        pred_classes_neg_sam = pred_classes_sam[pos:] 
        gt_classes_neg_sam = self.gt[pos:]
        if len(pred_classes_neg_sam) != 0:
            source_acc_neg_sam = (pred_classes_neg_sam.float() == gt_classes_neg_sam.float()).float().mean()
            source_binary_acc_neg_sam = (pred_classes_neg_sam.float() >= self.num_Cs).float().mean()
            self.summary_dict['acc/source_acc_neg_sam'] = source_acc_neg_sam
            self.summary_dict['acc/source_binary_acc_neg_sam'] = source_binary_acc_neg_sam


        # ===================================
        # ====== Accuracy over samples ======
        # ===================================
        
        if self.current_iteration >= self.settings['val_after']:
            concat_outputs_sample = torch.cat([self.features['Cs_sample'], self.features['Cn_sample']], dim=-1)
            concat_softmax_sample = F.softmax(concat_outputs_sample/self.settings['softmax_temperature'], dim=-1)
            pred_classes_sample = torch.argmax(concat_softmax_sample, dim=-1)
            pred_classes_sample = pred_classes_sample.view((pred_classes_sample.shape[0],))
            pos = self.settings['num_positive_samples']

            pred_classes_pos_samples = pred_classes_sample[:pos]
            gt_classes_pos_samples = self.gt_sample[:pos]
            source_acc_pos_samples = (pred_classes_pos_samples.float() == gt_classes_pos_samples.float()).float().mean()
            self.summary_dict['acc/source_acc_pos_samples'] = source_acc_pos_samples
        
        if self.phase == 'train':

            # ====== BACKPROP LOSSES ======
            enough_iters = (self.current_iteration >= self.settings['val_after'])
            l = len(self.which_optimizer)
            current_loss = self.which_optimizer[self.current_iteration%l]

            if self.settings['use_loss'][current_loss] and self.backward:
                
                print('\nApplying loss ' + str(self.which_optimizer[self.current_iteration%l]))

                if current_loss in self.settings['losses_after_enough_iters']:
                    print(self.current_iteration)
                    if self.current_iteration >= self.settings['val_after']:
                        print('{} >= {}'.format(self.current_iteration, self.settings['val_after']))
                        self.optimizer[self.which_optimizer[self.current_iteration%l]].zero_grad()
                        loss = self.get_loss(which_loss=self.which_optimizer[self.current_iteration%l])
                        print("loss",loss)
                        self.summary_dict['loss/' + str(self.which_optimizer[self.current_iteration%l])] = loss.cpu().detach().numpy()
                        loss.backward()
                        self.optimizer[self.which_optimizer[self.current_iteration%l]].step()
                else:
                    self.optimizer[self.which_optimizer[self.current_iteration%l]].zero_grad()
                    loss = self.get_loss(which_loss=self.which_optimizer[self.current_iteration%l])
                    print("else")
                    print(loss)
                    loss.backward()
                    self.optimizer[self.which_optimizer[self.current_iteration%l]].step()

        self.current_iteration += 1


    def get_negative_samples(self, num_samples):

        self.loader_train_negative

        return samples, gt


    def get_sample_embeddings(self, num_samples):
        # print('function get_sample_embeddings')
        # Positive samples
        N = self.settings['num_positive_samples']
        randclasses = torch.randint(0, self.num_C + self.num_Cs_dash, (N,)).cuda()  
        pos_samples = [self.mu_sigma_distribution[str(int(c))].sample((1,)) for c in randclasses]
        pos_gt = randclasses.clone().float()
        pos_samples = torch.cat(pos_samples, dim=0).cuda()

        return pos_samples, pos_gt


    def save_vec(self,vecs,vec_path,len_sam):
        print("sava vector")
        with open(vec_path,'w') as f:
            a=vecs.cuda().data.cpu().numpy()
            for i in range(len_sam):
                b = a[i]
                np.savetxt(f,b,newline=' ')
                f.write("\n")



    def forward(self, starts, paths, ends, labels,model,negative_starts,negative_paths,negative_ends,negative_labels):
    #def forward(self, starts, paths, ends, labels,model):
        # print('function forward')
        self.gt = labels
        self.pos_num=self.gt.shape[0]
        sam_source = model.vectorization((starts, paths, ends))
        #save vectors

        vec_path="/home/user/data/project5/nn_DA/attribution/authorship_pipeline/nn_output/vectors/vet.txt"
        self.save_vec(sam_source,vec_path,sam_source.shape[0])

        self.gt_neg = negative_labels
        sam_neg_source =model.vectorization((# Creating a list of negative numbers starting from -1
        # and going to -100.
        negative_starts, negative_paths, negative_ends))
        print(self.gt)
        print(self.gt_neg)
        self.gt = torch.cat([self.gt, self.gt_neg], dim=0)
        print("self.gt",self.gt)

        self.gt =self.gt.to(config_supervised.settings['device'])

        samples = torch.cat([sam_source, sam_neg_source], dim=0) 

        samples=samples.to(config_supervised.settings['device'])
        self.features = {}
        self.features['M'] = model.M(samples)

        self.features['Fs'] = model.Fs(self.features['M'])
        print("self.features['Fs'].shape",self.features['Fs'].shape)
        self.features['G'] = model.G(self.features['Fs'])
        self.features['Cs'] = model.Cs(self.features['Fs'])
        self.features['Cn'] = model.Cn(self.features['Fs'])

        if(0 in self.gt and 1 in self.gt):
            tem_0=[]
            tem_1=[]
            for i in range(64):
                if self.gt[i]==0:
                    tem_0.append(i)
                if self.gt[i]==1:
                    tem_1.append(i)
        if(0 in self.gt and 1 in self.gt):
            tem_feature=torch.zeros((1, 256)).to(config_supervised.settings['device'])
            j=tem_0[0]
            k=tem_1[0]
            tem_feature=torch.cat((tem_feature, self.features['Fs'][j:256]), 0) 
            tem_feature=torch.cat((tem_feature, self.features['Fs'][k:256]), 0) 
            from sklearn.metrics.pairwise import cosine_similarity
            cos_sim= cosine_similarity(self.features['Fs'].cuda().data.cpu().numpy())
            Lnc = torch.mean(torch.from_numpy(cos_sim))
            print("cos_sim is ______________",Lnc)
        # sigma......
        if self.current_iteration >= self.settings['val_after']:

            if (self.mu_sigma_distribution == None) or (self.current_iteration % self.settings['val_after'] == 0):
                self.recalculate_mu_sigma(model)

            self.features['Fs_sample'], self.gt_sample = self.get_sample_embeddings((samples.shape[0],)) # top half - positive, bottom half - negative
            self.features['G_sample'] = model.G(self.features['Fs_sample'])
            self.features['Fs_sample_recon'] = model.Fs(self.features['G_sample'])
            self.features['Cs_sample'] = model.Cs(self.features['Fs_sample'])
            self.features['Cn_sample'] = model.Cn(self.features['Fs_sample'])
        

    def train(self,model):
        
        global i
        if(i>=2):
            i=0
        global i_tar
        if(i_tar>=1):  #19 23
            i_tar=0
        print('function train')
        self.phase = 'train'
        self.summary_dict = {}
        dir={}
        for n_batch, sample in enumerate(self.loader_train):
            dir[n_batch]=sample

        self.sample=dir[i]   
        starts, paths, ends, labels = self.sample['starts'], self.sample['paths'], self.sample['ends'], self.sample['labels']
        starts=starts.to(config_supervised.settings['device'])
        paths=paths.to(config_supervised.settings['device'])
        ends=ends.to(config_supervised.settings['device'])
        labels=self.repair_Cs_labels(self.Cs, self.original_source_labels, labels)
        
        i+=1 
        dir_tar={}
        for n_batch, sample in enumerate(self.loader_train_negative):
            dir_tar[n_batch]=sample
        self.negative_sample=dir_tar[i_tar]
        negative_starts, negative_paths, negative_ends, negative_labels = self.negative_sample['starts'], self.negative_sample['paths'], self.negative_sample['ends'], self.negative_sample['labels']
        negative_starts=negative_starts.to(config_supervised.settings['device'])
        negative_paths=negative_paths.to(config_supervised.settings['device'])
        negative_ends=negative_ends.to(config_supervised.settings['device'])
        negative_labels=negative_labels+self.num_Cs
        i_tar+=1
        self.forward(starts, paths, ends, labels,model,negative_starts,negative_paths,negative_ends,negative_labels)
        self.loss()
        return self.summary_dict['acc/source_acc_pos_sam']


    def val(self):
        self.phase = 'val'
        self.summary_dict = {}
        self.forward()
        self.loss()


    def log_errors(self, phase, iteration=None):
        print('log errors phase: ' + str(phase) + '\n')
        print(self.summary_dict.keys())
        for x in list(sorted(self.summary_dict.keys())):
            print(x + ' : ' + str(float(self.summary_dict[x])))

            if phase == 'val':
                self.val_writer.add_scalar(x, self.summary_dict[x], self.current_iteration)
            elif phase == 'train':
                self.train_writer.add_scalar(x, self.summary_dict[x], self.current_iteration)    


    def set_mode_val(self,model):
        model.eval()
        self.backward = False
        for p in model.parameters():
            p.requires_grad = False
            p.volatile = True


    def set_mode_train(self,model):
        # print('function set_mode_train')

        model.train()
        self.backward = True
        for p in model.parameters():
            p.requires_grad = True
            p.volatile = False  
        
        for comp in self.settings['to_train']:
            if self.settings['to_train'][comp] == False:
                model.components[comp].eval()
                for p in model.components[comp].parameters():
                    p.requires_grad = False
                    p.volatile = True
    def get_val_set(self,model):
        starts=torch.zeros((1, 500))
        paths=torch.zeros((1, 500))
        ends=torch.zeros((1, 500))
        labels=torch.zeros((1))
        for n_batch, sample in enumerate(self.loader_train):
            starts_tmp, paths_tmp, ends_tmp, labels_tmp = sample['starts'], sample['paths'], sample['ends'], sample['labels']
            starts=torch.cat((starts, starts_tmp), 0)
            paths=torch.cat((paths, paths_tmp), 0) 
            ends=torch.cat((ends, ends_tmp), 0) 
            labels=torch.cat((labels, labels_tmp), 0)  
        starts=starts[torch.arange(starts.size(0))!=0].type(torch.LongTensor).to(config_supervised.settings['device'])
        paths=paths[torch.arange(paths.size(0))!=0].type(torch.LongTensor).to(config_supervised.settings['device'])
        ends=ends[torch.arange(ends.size(0))!=0].type(torch.LongTensor).to(config_supervised.settings['device'])
        self.labels_source=labels[torch.arange(labels.size(0))!=0].type(torch.LongTensor).to(config_supervised.settings['device'])

        self.x = model.vectorization((starts, paths, ends))
        self.x=self.x.to(config_supervised.settings['device'])

    def val_over_val_set(self,model):
        print('function val_over_val_set')

        with torch.no_grad():

            enough_iters = (self.current_iteration >= self.settings['val_after'])

            self.summary_dict = {}
            dataloader_source = self.loader_source_val 
            global j
            # if(j>=2):
            #     j=0
            dir={}
            for n_batch, sample in enumerate(self.loader_source_val):
                dir[n_batch]=sample

            self.sample=dir[0]   
            # j+=1
            starts, paths, ends, labels = self.sample['starts'], self.sample['paths'], self.sample['ends'], self.sample['labels']
            starts=starts.to(config_supervised.settings['device'])
            paths=paths.to(config_supervised.settings['device'])
            ends=ends.to(config_supervised.settings['device'])
            labels=self.repair_Cs_labels(self.Cs, self.original_source_labels, labels).to(config_supervised.settings['device'])
            x = model.vectorization((starts, paths, ends)).to(config_supervised.settings['device'])
            M = model.components['M'](x)
            # D = model.components['D'](M)
            Fs = model.components['Fs'](M)
            G = model.components['G'](Fs)
            print("Fs.shape",Fs.shape)
            Cs = model.components['Cs'](Fs)
            print("Cs.shape",Cs.shape)
            Cn = model.components['Cn'](Fs)
            print("Cn.shape",Cn.shape)

            concat_outputs = torch.cat([Cs, Cn], dim=-1)
            print("concat_outputs.shape",concat_outputs.shape)
            #concat_outputs=Cs
            concat_softmax = F.softmax(concat_outputs/self.settings['softmax_temperature'], dim=-1)
            print("concat_softmax.shape",concat_softmax.shape)
            max_act, pred = torch.max(concat_softmax, dim=-1)
            print("pred",pred)
            print("labels",labels)
            if len(pred) != 0:
                source_acc_pos_sam = (pred.float() == labels.float()).float().mean()
                self.summary_dict['acc/source_avg'] = source_acc_pos_sam
            
            return self.summary_dict


    def get_mu_sigma(self,model): # For tracking variance of each class in the training dataset
        _loader_train, _loader_source_val,_original_source_labels = NNClassifier.tmp_loder(self,path=project_folder_source)
        dataloader_source=self.loader_train
        features_source = []
        labels_source = []

        with torch.no_grad():

            for data in tqdm(dataloader_source):
                starts = data['starts'][:, :].float().cuda().type(torch.LongTensor).to(config_supervised.settings['device'])
                paths = data['paths'][:, :].float().cuda().type(torch.LongTensor).to(config_supervised.settings['device'])
                ends = data['ends'][:, :].float().cuda().type(torch.LongTensor).to(config_supervised.settings['device'])
                sam = model.vectorization((starts, paths, ends)).to(config_supervised.settings['device'])
                lab = data['labels'].float().cuda().type(torch.LongTensor).to(config_supervised.settings['device'])
                lab=self.repair_Cs_labels(self.Cs, self.original_source_labels, lab)
                M = model.components['M'](sam)
                print("M.shape",M.shape)
                # if (M.shape[0]<64):
                #     continue
                Fs = model.components['Fs'](M)

                features_source.append(Fs)
                labels_source.append(lab)

            features_source = torch.cat(features_source, dim=0)
            print("features_source.type")
            print(features_source)
            labels_source = torch.cat(labels_source, dim=0)
            print("labels_source.type")
            print(labels_source)

        mu_sigma_data = util.get_mu_sig(features_source, labels_source, self.num_C + self.num_Cs_dash, only_return=False)

        return mu_sigma_data
