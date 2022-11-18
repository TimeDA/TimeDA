import os
from model.server_path import server_root_path
from glob import glob
from natsort import natsorted

import matplotlib
# matplotlib.use('Agg')

import torch

settings = {}

settings['weights_path'] = os.path.join(server_root_path, 'weights')
settings['summaries_path'] = os.path.join(server_root_path, 'summaries')

settings['start_iter'] = 1
settings['max_iter'] = 600

settings['C'] = ["cosaka","darnley","eomole","hamadu","ivanpopelyshev","rabot","slex","tanzaku","uwi","Wolfje","dalex","eatmore","goalboy1015","it3","qwerty787788","Ratmir15","stolis","tsukuno","VArtem","xiaowuc1"]
settings['Cs_dash'] = []
settings['Ct_dash'] = []


settings['num_C'] = len(settings['C'])
settings['num_Cs_dash'] = len(settings['Cs_dash'])
settings['num_Ct_dash'] = len(settings['Ct_dash'])
settings['num_Cs'] = settings['num_C'] + settings['num_Cs_dash']
settings['num_Ct'] = settings['num_C'] + settings['num_Ct_dash']

settings['val_after'] = 20
settings['batch_size'] = 64

settings['num_positive_samples'] = settings['batch_size']
settings['num_negative_samples'] = settings['batch_size']

settings['cnn_to_use'] = 'resnet50'
settings['Fs_dims'] = 256
settings['softmax_temperature'] = 1
settings['online_augmentation_90_degrees'] = True # Used for online rotations in the data loader
settings['val_aug_sams_mean_before_softmax'] = False
settings['val_aug_sams_mean_after_softmax'] = True
settings['separate_target_validation_set'] = True
settings['target_train_val_split'] = 0.9

xor = lambda a, b: ((a and not(b)) or (not(a) and b))
assert xor(settings['val_aug_sams_mean_after_softmax'], settings['val_aug_sams_mean_before_softmax'])

# For adapt
settings['running_adapt'] = True
settings['load_weights'] = True
settings['load_exp_name'] = 'usfda_office_31_AtoD'
settings['exp_name'] = 'usfda_office_31_AtoD_adapt'

settings['optimizer'] = {
	'adaptation': ['Ft'],
	'Neighborhood_Clustering': ['Ft'],
}

settings['lambda'] = [1, 0.1]
settings['weight_computation_method'] = 3
settings['exponential_shift'] = 0

settings['use_loss'] = {
	'adaptation': False,
	'Neighborhood_Clustering': True,
}

settings['to_train'] = {
	'M': False, # -> only upto a certain conv layer. Needs to be frozen. We'll retrain the later layers.
	'Fs': False,
	'Ft': True,
	'G': False,
	'Cs': False,
	'Cn': False,
}
settings['lr'] = 0.005 # 1e-3 default

settings['gpu'] = 1
settings['device'] = 'cuda:' + str(settings['gpu'])
torch.cuda.set_device(settings['gpu'])

if settings['load_weights']:
	best_weights = natsorted(glob(os.path.join(settings['weights_path'], settings['load_exp_name'], '*.pth')))[-1]
	settings['load_weights_path'] = best_weights

settings['dataset_exp_name'] = 'gcj_cpp'
settings['dataset_path'] = os.path.join(server_root_path, 'data', settings['dataset_exp_name'], 'index_lists')
settings['negative_data_path'] = os.path.join(server_root_path, 'data', settings['dataset_exp_name'], 'negative_samples')
settings['negative_mask_path'] = os.path.join(server_root_path, 'data', settings['dataset_exp_name'], 'negative_masks')
