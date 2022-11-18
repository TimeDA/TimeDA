import torch
import torch.nn as nn
import torch.nn.functional as F
import torch.optim as optim
from torch.autograd import Variable
import numpy as np
import sys
import os
from torchvision import transforms, utils
import time
import cv2
import matplotlib.pyplot as plt
from matplotlib.backends.backend_agg import FigureCanvasAgg as FigureCanvas
from matplotlib.figure import Figure
from torch.distributions.multivariate_normal import MultivariateNormal
from skimage import io
from model.server_path import server_root_path
import time
from tqdm import tqdm
from torch.utils.data import DataLoader
from tensorboardX import SummaryWriter
import pdb
from sklearn.preprocessing import StandardScaler
from scipy.stats import norm
from scipy.interpolate import make_interp_spline, BSpline
from glob import glob

import model.config_adapt as config_adapt
import model.train_val_utils as util
from model.data_loader import TemplateDataset
from classifiers.BaseClassifier import BaseClassifier
from typing import Tuple, List, Union, Dict, Counter
from util import ProcessedFolder, ProcessedSnapshotFolder
from classifiers.NNClassifier import NNClassifier
from classifiers.config import Config
from model.get_vec import CodeToVec
from sklearn.metrics.pairwise import cosine_similarity
# from model.CodeVectorizer import CodeVectorizer

# vectorization=CodeVectorizer(20000, 20000, 256)
i=0
from model.LinearAverage import LinearAverage
from model.loss import *
ndata = 262 #target_folder.__len__()
## Memory
lemniscate = LinearAverage(256, ndata, 0.05, 0.0).cuda()
class TrainerG(NNClassifier):

    def __init__(self, config: Config, model,project_folder: ProcessedFolder, min_max_count: Tuple[int, int], 
                    network, optimizer, exp_name, settings,change_entities=None,change_to_time_bucket=None,author_occurrences=None,
                 context_splits=None):
        super(TrainerG, self).__init__(config, project_folder, min_max_count, 
                change_entities, change_to_time_bucket, author_occurrences, context_splits)
    
        # Set the network and optimizer
        #self.network = network
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
        self.Ct = settings['C'] + settings['Ct_dash']
        # Get number of classes
        self.num_C = settings['num_C']
        self.num_Cs_dash = settings['num_Cs_dash']
        self.num_Ct_dash = settings['num_Ct_dash']
        self.num_Cs = settings['num_Cs']
        self.num_Ct = settings['num_Ct']

        # Initialize data loaders
        #self.get_all_dataloaders()
        self.__sample_loaders()

    def __sample_loaders(self, fold_ind: Union[int, Tuple[int, int]] = 0) -> Tuple[DataLoader, DataLoader]:
        # java
        project_folder_source="/home/zss/data/project5/nn_DA/processed/gcj_java/gcj2017/java/"
        # project_folder_source="/home/zss/data/project5/nn_DA/processed/cpp_12_18/gcj2017/cpp/"
        self.loader_train, self.loader_target_val, self.original_target_labels = NNClassifier.tmp_loder(self,path=project_folder_source)
        print(self.original_target_labels)

    def repair_Ct_labels(self,Ct,Ct_labels,Ct_lable_id):
        result = []
        for i in Ct_lable_id:
            result.append(Ct.index(Ct_labels[i]))
        result = torch.LongTensor(result)
        return result
    
    def get_all_dataloaders(self):
        
        dataset_train = TemplateDataset(self.index_list_train_target, transform=transforms.Compose([transforms.ToTensor()]), random_choice=False)
        self.loader_train = DataLoader(dataset_train, batch_size=self.batch_size, shuffle=True, num_workers=2)

        dataset_target_val = TemplateDataset(self.index_list_val_target, transform=transforms.Compose([transforms.ToTensor()]), random_choice=False)
        self.loader_target_val = DataLoader(dataset_target_val, batch_size=self.batch_size, shuffle=True, num_workers=2)


    def get_histogram(self, features, bin_size=0.01, normalize=True):
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


    def get_prefix(self):
        
        return ''


    def weight_computation_step(self, concat_softmax):
        print(concat_softmax.shape)
        # Only exp max conf
        if self.settings['weight_computation_method'] == 1:
            num_Cs = self.num_C + self.num_Cs_dash
            W, _ = torch.max(concat_softmax[:, :num_Cs], dim=-1)
            W = torch.exp(self.settings['exponential_shift'] + W)
            return W.squeeze(), (1-W).squeeze()
        
        # Exp max conf normalized over batch
        elif self.settings['weight_computation_method'] == 2:
            num_Cs = self.num_C + self.num_Cs_dash
            W, _ = torch.max(concat_softmax[:, :num_Cs], dim=-1)
            W1 = torch.exp(self.settings['exponential_shift'] + W)
            W1 = ( W1 - torch.min(W1) ) / ( torch.max(W1) - torch.min(W1) )
            W2 = torch.exp(self.settings['exponential_shift'] + 1-W)
            W2 = ( W2 - torch.min(W2) ) / ( torch.max(W2) - torch.min(W2) )
            return W1.squeeze(), W2.squeeze()

        # Sum conf in Cs / Cn
        elif self.settings['weight_computation_method'] == 3:
            num_Cs = self.num_C + self.num_Cs_dash
            W = torch.sum(concat_softmax[:, :num_Cs], dim=-1)
            return W.squeeze(), (1-W).squeeze()

        # Sum conf in Cs / Cn normalized
        elif self.settings['weight_computation_method'] == 4:
            num_Cs = self.num_C + self.num_Cs_dash
            W = torch.sum(concat_softmax[:, :num_Cs], dim=-1)
            W1 = W / torch.max(W)
            W2 = (1-W) / torch.max(1-W)
            return W1.squeeze(), W2.squeeze()

        # Sum conf in Cs / Cn exponential normalized
        elif self.settings['weight_computation_method'] == 5:
            num_Cs = self.num_C + self.num_Cs_dash
            W = torch.sum(concat_softmax[:, :num_Cs], dim=-1)
            W1 = torch.exp(self.settings['exponential_shift'] + W)
            W1 = W / torch.max(W)
            W2 = torch.exp(self.settings['exponential_shift'] + 1-W)
            W2 = (1-W) / torch.max(1-W)
            return W1.squeeze(), W2.squeeze()


    def get_loss(self, which_loss):

        if which_loss == 'adaptation':

            num_Cs = self.num_C + self.num_Cs_dash

            concat_outputs = torch.cat([self.features['Cs'], self.features['Cn']], dim=-1)
            y_cap = F.softmax(concat_outputs/self.settings['softmax_temperature'], dim=-1)
            
            w_concat_outputs = torch.cat([self.features['w_Cs'], self.features['w_Cn']], dim=-1)
            w_y_cap = F.softmax(w_concat_outputs/self.settings['softmax_temperature'], dim=-1)
            W1, W2 = self.weight_computation_step(w_y_cap)

            # Detach W from the graph
            W1 = torch.from_numpy(W1.cpu().detach().numpy()).cuda()

            # Soft binary entropy way of pushing samples to the corresponding regions
            y_cap_s = torch.sum(y_cap[:, :num_Cs], dim=-1)
            y_cap_n = 1 - y_cap_s

            Ld_1 = W1 * (-torch.log(y_cap_s)) + W2 * (-torch.log(y_cap_n))

            # Soft categorical entropy way of pushing samples to the corresponding regions
            y_tilde_s = F.softmax(self.features['Cs']/self.settings['softmax_temperature'], dim=-1)
            y_tilde_n = F.softmax(self.features['Cn']/self.settings['softmax_temperature'], dim=-1)
            #print(self.features['Cs'])
            H_s = - torch.sum(y_tilde_s * torch.log(y_tilde_s), dim=-1)
            H_n = - torch.sum(y_tilde_n * torch.log(y_tilde_n), dim=-1)
            Ld_2 = W1 * H_s + W2 * H_n  
            l1, l2 = self.settings['lambda']
            loss_over_batch = Ld_1 * l1 + Ld_2 * l2
            loss = torch.mean( loss_over_batch , dim=0 )
        elif(which_loss == 'Neighborhood_Clustering'):
            cos_sim= cosine_similarity(self.features['Ft'].cuda().data.cpu().numpy())/0.05
            cos_sim= torch.exp(torch.tensor(cos_sim))
            s = torch.zeros(1,cos_sim.shape[1]-1).cuda()
            for j in range(cos_sim.shape[1]-1):
                s[0,j]=cos_sim[0,j]/torch.sum(cos_sim[0,1:])
            Lnc = -torch.mean(torch.sum(s*torch.log(s+1e-5)))
            loss=torch.tensor(Lnc,requires_grad=True)
        else:
            raise NotImplementedError('Not implemented loss function ' + str(which_loss))

        self.summary_dict['loss/' + str(which_loss)] = loss.data.cpu().numpy()
        return loss


    def loss(self):
        concat_outputs = torch.cat([self.features['Cs'], self.features['Cn']], dim=-1)
        concat_softmax = F.softmax(concat_outputs/self.settings['softmax_temperature'], dim=-1)
        
        pred = torch.argmax(concat_softmax, dim=-1)
        print("pred",pred)
        pred[pred >= (self.num_C + self.num_Cs_dash)] = (self.num_C + self.num_Cs_dash)
        print("pred",pred)

        print(self.gt)
        target_acc = (pred.float() == self.gt.float()).float().mean()
        self.summary_dict['acc/target_acc'] = target_acc
        
        if self.phase == 'train':

            # ====== BACKPROP LOSSES ======
            enough_iters = (self.current_iteration >= self.settings['val_after'])
            l = len(self.which_optimizer)
            current_loss = self.which_optimizer[self.current_iteration%l] #current_loss="adaptation"
            

            if self.settings['use_loss'][current_loss] and self.backward:
                
                print('\nApplying loss ' + str(self.which_optimizer[self.current_iteration%l]))

                self.optimizer[self.which_optimizer[self.current_iteration%l]].zero_grad()
                loss = self.get_loss(which_loss=self.which_optimizer[self.current_iteration%l])
                print("loss.shape",loss.shape)
                loss.backward()
                self.optimizer[self.which_optimizer[self.current_iteration%l]].step()
        
        self.current_iteration += 1


    def forward(self, starts, paths, ends, labels,model):
        self.gt = labels.to(config_adapt.settings['device'])
        starts=starts.to(config_adapt.settings['device'])
        paths=paths.to(config_adapt.settings['device'])
        ends=ends.to(config_adapt.settings['device'])
        self.sam_target = model.vectorization((starts, paths, ends)).to(config_adapt.settings['device'])
        self.gt[self.gt >= self.num_C] = (self.num_C + self.num_Cs_dash) # Club all the target private classes into an unknown class
        self.features = {}
        # Target data
        self.features['M'] = model.M(self.sam_target)
        self.features['Ft'] = model.Ft(self.features['M'])
        self.features['Cs'] = model.Cs(self.features['Ft'])
        self.features['Cn'] = model.Cn(self.features['Ft'])

        # Passing target data through source cfier for getting the weight

        with torch.no_grad():
            self.features['w_Fs'] = model.Fs(self.features['M'])
            self.features['w_Cs'] = model.Cs(self.features['w_Fs'])
            self.features['w_Cn'] = model.Cn(self.features['w_Fs'])

    def train(self,model):
        global i
        if(i>=4):
            i=0
        print('function train')
        self.phase = 'train'
        self.summary_dict = {}
        dir={}
        for n_batch, sample in enumerate(self.loader_train):
            dir[n_batch]=sample

        self.sample=dir[i]   
        starts, paths, ends, labels = self.sample['starts'], self.sample['paths'], self.sample['ends'], self.sample['labels']
        print("labels",labels)
        labels=self.repair_Ct_labels(self.Ct, self.original_target_labels, labels)
        #print("labels",labels.shape)
        print("labels",labels)
        i+=1 
        self.forward(starts, paths, ends, labels,model)
        self.loss()

        return self.summary_dict['acc/target_acc']


    def log_errors(self, phase, iteration=None):
        
        print('log errors phase: ' + str(phase) + '\n')
        print(self.summary_dict.keys())

        for x in self.summary_dict.keys():
            print(x + ' : ' + str(float(self.summary_dict[x])))

            if phase == 'val':
                self.val_writer.add_scalar(self.get_prefix() + x, self.summary_dict[x], self.current_iteration)
            elif phase == 'train':
                self.train_writer.add_scalar(self.get_prefix() + x, self.summary_dict[x], self.current_iteration)    


    def set_mode_val(self,model):

        model.eval()
        self.backward = False
        for p in model.parameters():
            p.requires_grad = False
            p.volatile = True


    def set_mode_train(self,model):

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
    

    def val_over_val_set(self,model):

        with torch.no_grad():

            enough_iters = (self.current_iteration >= self.settings['val_after'])

            self.summary_dict = {}
    
            # --------------
            # Target Dataset
            # --------------

            print('\nValidating on target validation data')
            dataloader_target = self.loader_train
            num_C = self.num_C
            num_Cs_dash = self.num_Cs_dash
            num_Ct_dash = self.num_Ct_dash
            num_Cs = self.num_Cs
            num_Ct = self.num_Ct

            with torch.no_grad():

                # Running calculations of accuracy

                a_private_acc = 0
                private_count = 0

                classes = list(range(num_C))
                classes.append(num_C+num_Cs_dash)

                a_avg_count = {c:0 for c in classes}
                a_avg_acc = {c:0 for c in classes}
                idx = -1
                Cs=self.features['Cs']
                Cn=self.features['Cn']
                concat_outputs = torch.cat([Cs, Cn], dim=-1)                

                labels_target=self.gt
                labels_target[labels_target>=num_C] = (self.num_C + self.num_Cs_dash)
                #print("labels_target",labels_target)
                concat_softmax = F.softmax(concat_outputs/self.settings['softmax_temperature'], dim=-1)
                max_act, pred = torch.max(concat_softmax, dim=-1)
                #print("pred",pred)
                pred[pred>=(num_Cs)] = (self.num_C + self.num_Cs_dash)
                private_count += pred[labels_target>=num_C].shape[0] 
                #print("private_count",private_count)
                for c in classes: # for all the shared and the unknown labels
                    a_avg_count[c] += pred[labels_target==c].shape[0]
                a_pred = []
                a_Cs=self.features['Cs']
                a_Cn=self.features['Cn']
                a_concat_outputs = torch.cat([a_Cs, a_Cn], dim=-1)
                a_concat_softmax = F.softmax(a_concat_outputs/self.settings['softmax_temperature'], dim=-1)
                a_pred_temp = torch.argmax(a_concat_softmax, dim=-1)
                a_pred_temp=a_pred_temp.tolist()
                i=0
                for i in range(0,len(a_pred_temp)):
                            
                    if a_pred_temp[i] >= num_Cs:
                        a_pred_temp[i] = self.num_C + self.num_Cs_dash
                a_pred=a_pred_temp
                a_pred = torch.LongTensor(a_pred).to(config_adapt.settings['device'])
                a_private_acc += (a_pred[labels_target>=num_C] == labels_target[labels_target>=num_C]).float().sum()
                for c in classes:
                    a_avg_acc[c] += (a_pred[labels_target==c] == labels_target[labels_target==c]).float().sum()    
                # average accuracy
                a_avg = 0
                num_classes = num_C + 1
                classes = list(range(num_C))
                classes.append(num_C+num_Cs_dash)
                for c in classes:
                    print("a_avg_acc[c]",a_avg_acc[c])

                    if a_avg_count[c] == 0:
                        a_avg += 0
                    else:
                        a_avg += (float(a_avg_acc[c]) / float(a_avg_count[c]))
                a_avg /= float(num_classes)
                self.summary_dict['acc/target_aa_avg'] = a_avg
                concat_outputs = torch.cat([Cs, Cn], dim=-1)
                concat_softmax = F.softmax(concat_outputs/self.settings['softmax_temperature'], dim=-1)

                pred = torch.argmax(concat_softmax, dim=-1)
                print("pred",pred)
                pred[pred >= (self.num_C + self.num_Cs_dash)] = (self.num_C + self.num_Cs_dash)
                print("pred",pred)
                print("self.gt",self.gt)
                target_acc = (pred.float() == self.gt.float()).float().mean()
                self.summary_dict['acc/target_a_avg'] = target_acc
                
            return self.summary_dict['acc/target_a_avg']