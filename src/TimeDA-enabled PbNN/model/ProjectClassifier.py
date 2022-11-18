from torch import nn

from model.CodeVectorizer import CodeVectorizer
from model import config_supervised

Fs_dims = config_supervised.settings['Fs_dims']

class ProjectClassifier(nn.Module):

    def __init__(self, n_tokens, n_paths, dim, n_classes, additional_components=[]):
        super(ProjectClassifier, self).__init__()
        
        self.vectorization = CodeVectorizer(n_tokens, n_paths, dim)
        self.M = nn.Sequential(
            nn.Linear(dim, dim),
            nn.Tanh()
            )
        
        # self.D = nn.Dropout(p=0.1)
        self.Fs = nn.Sequential(
            nn.Linear(dim,dim), 
            
            nn.BatchNorm1d(dim),
            nn.Tanh(),
            nn.Dropout(p=0.2),               
        )
        #self.dropout = nn.Dropout(p=0.5)
        self.Ft = nn.Sequential(
            nn.Linear(dim,dim), 
            
            nn.BatchNorm1d(dim),
            nn.Tanh(),
            nn.Dropout(p=0.2),
        )
        self.G = nn.Sequential(
            nn.Linear(dim,dim),
            nn.Dropout(p=0.2),
            nn.Tanh()
        )
        
        self.Cs = nn.Sequential(
            nn.Linear(dim, config_supervised.settings['num_C'] + config_supervised.settings['num_Cs_dash'])
        )
        n = config_supervised.settings['num_C'] + config_supervised.settings['num_Cs_dash']
        # cpp
        num_negative_classes =21 
        # java
        # num_negative_classes =20 
        self.Cn = nn.Sequential(
            nn.Linear(dim, num_negative_classes)
        )
        self.components = {
                    'M': self.M,
                    # 'D':self.D,
                    'Fs': self.Fs,
                    'Ft': self.Ft,
                    'G': self.G,
                    'Cs': self.Cs,
                    'Cn': self.Cn,
                }

    def forward(self, contexts):
        vectorized_contexts = self.vectorization(contexts)
        M_featurs = self.M(vectorized_contexts)
        predictions_Cs = self.Cs(M_featurs)
        predictions_Cn = self.Cn(M_featurs)
        return predictions_Cs

