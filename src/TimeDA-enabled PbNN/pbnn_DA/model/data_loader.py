import numpy as np
from torch.utils.data import Dataset, DataLoader
from skimage import io, transform
from torchvision import transforms, utils
import torch
import os
from model.server_path import server_root_path

import model.config_supervised

class TemplateDataset(Dataset):
    
    def __init__(self, view_params_set, transform=None, random_choice=True, online_augmentation_90_degrees=None):
        
        self.view_params_set = view_params_set
        self.transform = transform
        self.data = {} 
        self.random_choice = random_choice
        self.online_augmentation_90_degrees = online_augmentation_90_degrees
        
    def __len__(self):
        if self.random_choice:
            return 1000000
        else:
            return len(self.view_params_set)

    def get_random_90_degree_augmentation(self, sam):
        assert (sam.shape == (224, 224, 3)) or (sam.shape == (32, 32, 3))

        if type(sam) == np.ndarray:
            sam = transforms.ToPILImage()(sam)

        angle = np.random.choice([-90, 90])
        new_sam = transforms.functional.rotate(sam, float(angle))

        return new_sam
    
    def __getitem__(self, idx):

        if self.random_choice:
            idx = np.random.choice(np.arange(len(self.view_params_set)), 1)[0]
        if (isinstance(self.view_params_set[idx], str)):
            sam_name = os.path.join(server_root_path, self.view_params_set[idx])
        else:
            sam_name = os.path.join(server_root_path, str(self.view_params_set[idx],encoding="utf-8"))
        sample = io.imread(sam_name)
        sample_cp = sample
        if self.online_augmentation_90_degrees is None:
            if config_supervised.settings['online_augmentation_90_degrees']:
                sample_cp = self.get_random_90_degree_augmentation(sample_cp)
        else:
            if self.online_augmentation_90_degrees:
                sample_cp = self.get_random_90_degree_augmentation(sample_cp)
        res = transforms.Compose([transforms.ToTensor()])
        sample_cp = res(sample_cp)
        if self.transform:
            sample = self.transform(sample)
        norm = transforms.Normalize(mean=[0.485, 0.456, 0.406],std=[0.229, 0.224, 0.225])
        sample = norm(sample)    
        self.data['sam'] = torch.tensor(sample)
        self.data['label'] = int(sam_name.split('_')[-4])
        # print 'label', self.data['label']
        self.data['raw'] = sample_cp
        self.data['filename'] = sam_name
    
        return self.data.copy()