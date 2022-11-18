import torch
from torch.autograd import Variable
from torch.distributions.multivariate_normal import MultivariateNormal
import matplotlib.pyplot as plt
import numpy as np
import torch.nn.functional as F
from tqdm import tqdm

from natsort import natsorted
import model.config_supervised as config_supervised

def PCA(data_pca, k):
    data_mean = torch.mean(data_pca,0)
    data_pca = data_pca - data_mean.expand_as(data_pca)
    U,S,V = torch.svd(torch.t(data_pca))
    Components = torch.mm(data_pca,U[:,:k])
    return Components

def Get_Full_Data(loader, net_G, which_fext = 'original', vgg_feats = True, which_level_features='default', use_numpy=False):
    
    label_list = []
    feature_list = []
    common_embedding_list = []
    prediction_list = []
    vggrec_list = []
    vggfeats_list = []

    L = len(loader)
    loader = enumerate(loader)
    i = 0
    
    with torch.no_grad():
        while(True):
            try:
                data = loader.next()[1]
                i+=1
                if i%10==0:
                    print(str(i) + ' / ' + str(L))
            except:
                break

            x = Variable(data['sam'][:, :3, :, :]).to(config_supervised.settings['device']).float()

            if which_level_features=='default':
                prediction, feature, vggrec, vggfeats = net_G.forward(x, which_fext=which_fext)
            else:
                prediction, feature, vggrec, vggfeats = net_G.forward_and_get_features(x, which_fext=which_fext, which_level_features=which_level_features)
                feature = feature.cpu()

            if vgg_feats:
                vggrec_list.append(vggrec.detach())
                vggfeats_list.append(vggfeats.detach())
            feature_list.append(feature.detach())
            prediction_list.append(prediction.detach())
            label = Variable(torch.LongTensor(data['label'])).to(config_supervised.settings['device']).float()
            label_list.append(label.detach())

        if use_numpy:
            data_x = np.concatenate(feature_list, 0)
            data_y = np.concatenate(label_list, 0)   
            data_pred = np.concatenate(prediction_list, 0)
        else:
            data_x = torch.cat(feature_list, 0)
            data_y = torch.cat(label_list, 0)	
            data_pred = torch.cat(prediction_list, 0)

        if vgg_feats:
            if use_numpy:
                data_vggrec = np.concatenate(vggrec_list, 0)
                data_vggfeats = np.concatenate(vggfeats_list, 0) 
            else:
                data_vggrec = torch.cat(vggrec_list, 0)
                data_vggfeats = torch.cat(vggfeats_list, 0)
    if vgg_feats:
        return data_x, data_y, data_pred, data_vggrec, data_vggfeats
    else:
        return data_x, data_y, data_pred, None, None


def Get_Cov_Mean(features):
    # Features = (D, N)
    features_mean = torch.mean(features,dim=1)
    print("features",features.shape)
    print("features_mean",features_mean.shape)
    print("features_mean[:, None]",features_mean[:, None].shape)
    mean_cen_feat = features - features_mean[:, None]
    print("mean_cen_feat",mean_cen_feat.shape)
    COV = 1.0/(mean_cen_feat.size(1)-1) * mean_cen_feat.mm(mean_cen_feat.t())
    MEAN = features_mean
    eps = 1e-3 * torch.eye(COV.shape[0]).to(config_supervised.settings['device'])
    return COV+eps, MEAN

def get_mu_sig(feature_trans, labels, num_classes, only_return = False):
    cov = []
    std = []
    mean = []
    boundary = []
    mean_value = []
    eig_dir = []
    print("feature_trans",feature_trans.shape)
    COV, MEAN = Get_Cov_Mean(feature_trans.t())
    # print feature_trans.t().shape
    u,s,v = torch.svd(COV)  
    eigen_direction_big_circle = torch.matmul(v, torch.sqrt(s)) 
    # here range = number of categories. hence, take care to change accordingly
    for i in tqdm(range(num_classes)):
        new_ft = feature_trans[labels==i]
        print("features1.shape",new_ft.shape)
        features = new_ft.t()  
        print("features2.shape",features.shape)
        # print features.shape
        tmp_cov, tmp_mean = Get_Cov_Mean(features)
        std.append(torch.sqrt(torch.diag(tmp_cov)))
        cov.append(tmp_cov)
        mean.append(tmp_mean)
        # print(tmp_cov)
        # print([float(tmp_cov[i, i]) for i in range(tmp_cov.shape[0])])
        newd = MultivariateNormal(tmp_mean, tmp_cov)
        llh = newd.log_prob(tmp_mean)
        mean_value.append(llh)
        u,s,v = torch.svd(tmp_cov)
        eigen_direction = torch.matmul(v, torch.sqrt(s))
        eig_dir.append(eigen_direction)

    data = {}
    for i in range(num_classes):
        # print mean[i], cov[i], eig_dir[i]
        data[str(i)] = [mean[i].data.cpu().numpy(), cov[i].data.cpu().numpy(), eig_dir[i].data.cpu().numpy()]
    data['full_circle'] = [MEAN.data.cpu().numpy(), COV.data.cpu().numpy(), eigen_direction_big_circle]

    if only_return:
        return data
    else:
        np.save('mu_sigmanew', data)
        return data
