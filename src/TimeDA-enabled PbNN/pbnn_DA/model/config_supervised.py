import os
from model.server_path import server_root_path
from glob import glob
from natsort import natsorted
import matplotlib
import torch

server_root_path="/home/zss/data/project5/nn_DA"
# Settings are passed through this dictionary
settings = {}

# Paths of weights and summaries to be saved
settings['weights_path'] = os.path.join(server_root_path, 'weights')
settings['summaries_path'] = os.path.join(server_root_path, 'summaries')

# For supervised training. Set to false, if Train_supervised.py should not be executed.
settings['running_supervised'] = True

# Maximum number of iterations
settings['start_iter'] = 1
settings['max_iter'] = 400 
settings['val_after'] = 12

# Label set relationships
settings['C'] = ["cosaka","darnley","eomole","hamadu","ivanpopelyshev","rabot","slex","tanzaku","uwi","Wolfje","dalex","eatmore","goalboy1015","it3","qwerty787788","Ratmir15","stolis","tsukuno","VArtem","xiaowuc1"]
settings['Cs_dash'] = []
settings['Ct_dash'] = []

settings['num_C'] = len(settings['C'])
settings['num_Cs_dash'] = len(settings['Cs_dash'])
settings['num_Ct_dash'] = len(settings['Ct_dash'])
settings['num_Cs'] = settings['num_C'] + settings['num_Cs_dash']
settings['num_Ct'] = settings['num_C'] + settings['num_Ct_dash']

# Batch Size and number of samples per iteration
settings['batch_size'] = 64

settings['num_positive_samples'] = settings['batch_size']
settings['num_negative_samples'] = settings['batch_size']

# Model parameters
settings['cnn_to_use'] = 'resnet50'
settings['Fs_dims'] = 256
settings['softmax_temperature'] = 1
settings['online_augmentation_90_degrees'] = True # Used for online rotations in the data loader
settings['val_aug_sams_mean_before_softmax'] = False
settings['val_aug_sams_mean_after_softmax'] = True

# Loading weights and experiment name. Change the experiment name here, to save the weights with the 
# corresponding exp_name. The weights of this can then be loaded into another experiment, by setting
# load_exp_name.
settings['load_weights'] = False
settings['load_exp_name'] = 'None'
settings['exp_name'] = 'usfda_office_31_AtoD'

# Define optimizers for the various losses.
settings['optimizer'] = {
	'classification': ['M', 'Fs', 'Cs', 'Cn'], # Classification loss
	'pos_sam_recon': ['Fs', 'G'], # Sample cyclic reconstruction loss
	'pos_sample_recon': ['Fs', 'G'], # Feature cyclic reconstruction loss
	'logsoftmax': ['Fs'], # Loss over PDF values of features (to make the clusters compact and separated)
}

settings['use_loss'] = {
	'classification': True,
	'pos_sam_recon': False,
	'pos_sample_recon': False,
	'logsoftmax': False,
}

settings['losses_after_enough_iters'] = ['logprob', 'logsoftmax', 'pos_sample_recon']

# settings['classification_weight'] = [1, 0.2] # Hyperparameter alpha -> second element of the list.
settings['classification_weight'] = [1, 0.1] # Hyperparameter alpha -> second element of the list.

settings['to_train'] = {
	'M': True, # Frozen Resnet-50
	'Fs': True,
	'Ft': False,
	'G': True,
	'Cs': True,
	'Cn': True,
}

settings['lr'] =0.005 #1e-4 # 1e-3 default   
settings['gpu'] = 1
settings['device'] = 'cuda:' + str(settings['gpu'])
# settings['device'] = 'cpu'
torch.cuda.set_device(settings['gpu'])

if settings['load_weights']:
	best_weights = natsorted(glob(os.path.join(settings['weights_path'], settings['load_exp_name'], '*.pth')))[-1]
	settings['load_weights_path'] = best_weights

settings['dataset_exp_name'] = 'gcj_cpp'

settings['dataset_path'] = os.path.join(server_root_path, 'data', settings['dataset_exp_name'], 'index_lists') 
settings['negative_data_path'] = os.path.join(server_root_path, 'data', settings['dataset_exp_name'], 'negative_samples') 
settings['negative_mask_path'] = os.path.join(server_root_path, 'data', settings['dataset_exp_name'], 'negative_masks')
