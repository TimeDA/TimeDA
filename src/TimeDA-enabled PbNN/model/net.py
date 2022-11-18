import torch.nn as nn
import torch.nn.functional as F
import torch.utils.model_zoo as model_zoo
import pdb
import torch
from torch.autograd import Variable
from torchvision import models

import config_supervised 

Fs_dims = config_supervised.settings['Fs_dims']
cnn_to_use = config_supervised.settings['cnn_to_use']

class CustomResNet(nn.Module):

    def __init__(self):

        super(CustomResNet, self).__init__()

        temp_resnet = models.resnet50(pretrained=True)  
        self.features = nn.Sequential(*[x for x in list(temp_resnet.children())[:-1]]) # Upto the avgpool layer

    def forward(self, x):

        feats = self.features(x)
        return feats.view((x.shape[0], 2048))


class modnet(nn.Module):
    
    def __init__(self, num_C, num_Cs_dash, num_Ct_dash, cnn=cnn_to_use, additional_components=[]): 
        
        super(modnet, self).__init__()

        # Frozen initial conv layers
        if cnn=='resnet50':
            self.M = CustomResNet()
        else:
            raise NotImplementedError('Not implemented for ' + str(cnn))

        self.Fs = nn.Sequential(
            nn.Linear(2048,1024),
            nn.ELU(),
            nn.Linear(1024,1024),
            nn.BatchNorm1d(1024),
            nn.ELU(),
            nn.Linear(1024,Fs_dims),
            nn.ELU(),
            nn.Linear(Fs_dims, Fs_dims),
            nn.BatchNorm1d(Fs_dims),
            nn.ELU(),
        )

        self.Ft = nn.Sequential(
            nn.Linear(2048,1024),
            nn.ELU(),
            nn.Linear(1024,1024),
            nn.BatchNorm1d(1024),
            nn.ELU(),
            nn.Linear(1024,Fs_dims),
            nn.ELU(),
            nn.Linear(Fs_dims, Fs_dims),
            nn.BatchNorm1d(Fs_dims),
            nn.ELU(),
        )

        self.G = nn.Sequential(
            nn.Linear(Fs_dims,1024),
            nn.ELU(),
            nn.Linear(1024,1024),
            nn.BatchNorm1d(1024),
            nn.ELU(),
            nn.Linear(1024,2048),
            nn.ELU(),
            nn.Linear(2048, 2048),
        )

        self.Cs = nn.Sequential(
            nn.Linear(Fs_dims, num_C + num_Cs_dash)
        )

        # Negative class classifier. Change this to vary the size of the negative class classifier.
        n = config_supervised.settings['num_C'] + config_supervised.settings['num_Cs_dash']
        num_negative_classes = int(n*(n-1)/2) 
        # num_negative_classes = 150

        self.Cn = nn.Sequential(
            nn.Linear(Fs_dims, num_negative_classes)
        )

        self.components = {
            'M': self.M,
            'Fs': self.Fs,
            'Ft': self.Ft,
            'G': self.G,
            'Cs': self.Cs,
            'Cn': self.Cn,
        }

    def forward(self, x, which_fext='original'):
        raise NotImplementedError('Implemented a custom forward in train loop')


def no_param(model):
    param = 0
    for p in list(model.parameters()):
        n=1
        for i in list(p.size()):
            n*= i
        param += n
    return param


if __name__=='__main__':
    raise NotImplementedError('Please check README.md for execution details')
