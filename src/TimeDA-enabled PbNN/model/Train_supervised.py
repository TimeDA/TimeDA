import torch
import torch.nn as nn
import torch.nn.functional as F
import torch.optim as optim
from torch.autograd import Variable
import numpy as np
import sys
import os
import net
import matplotlib.pyplot as plt
from matplotlib.backends.backend_agg import FigureCanvasAgg as FigureCanvas
from matplotlib.figure import Figure
from torch.utils.data import DataLoader
from time import time
from tqdm import tqdm
import subprocess
import warnings
from torchvision import transforms
from tensorboardX import SummaryWriter

import config_supervised as config
from Trainer_supervised import TrainerG
import train_val_utils as util
from data_loader import TemplateDataset

#warnings.simplefilter("ignore", UserWarning)

# ==================== END OF SANITY CHECK ==================== #

max_val_source_acc = -10000
itt_delete = []

def main():

	print('\n Setting up data sources ...')

	# ====== DELETE PAST RUNS ======
	torch.cuda.set_device(config.settings['gpu'])
	exp_name = config.settings['exp_name']
	subprocess.call(["rm", "-rf", os.path.join(config.settings['weights_path'],exp_name)])
	subprocess.call(["mkdir", os.path.join(config.settings['weights_path'],exp_name)])
	subprocess.call(["rm", "-rf", os.path.join(config.settings['summaries_path'],exp_name)])
	subprocess.call(["mkdir", os.path.join(config.settings['summaries_path'],exp_name)])
	subprocess.call(["mkdir", os.path.join(config.settings['summaries_path'],exp_name)+"/logdir_train"])
	subprocess.call(["mkdir", os.path.join(config.settings['summaries_path'],exp_name)+"/logdir_val"])

	with open(os.path.join(config.settings['summaries_path'], config.settings['exp_name'], 'config.txt'), 'w') as history_file:
		print('saving in ' + os.path.join(config.settings['summaries_path'], config.settings['exp_name'], 'config.txt'))
		history_file.write('\n===== x ===== x =====\n')
		for key in sorted(config.settings.keys()):
			history_file.write('{}: {}\n'.format(key, config.settings[key]))
	
	# ====== DEFINE DATA SOURCES ======
	index_list_path_train_source = os.path.join(config.settings['dataset_path'], 'source_samples_index_list_train.npy')
	index_list_path_val_source = os.path.join(config.settings['dataset_path'], 'source_samples_index_list_val.npy')
	index_lists = [index_list_path_train_source, index_list_path_val_source, None, None, None, None]

	# ====== CREATE NETWORK ======
	print('\n Building network ...')
	network = net.modnet(config.settings['num_C'], config.settings['num_Cs_dash'], config.settings['num_Ct_dash'], cnn=config.settings['cnn_to_use']).cuda()
	
	# Load weights
	if config.settings['load_weights']:
		dict_to_load = torch.load(config.settings['load_weights_path'])
		for component in dict_to_load:
			network.components[component].load_state_dict(dict_to_load[component])
		
	# ====== DEFINE OPTIMIZERS ======
	print('\n Setting up optimizers ...')
	optimizer = {}

	for key in config.settings['use_loss']:
		if config.settings['use_loss'][key]:
			to_train = []
			for comp in config.settings['optimizer'][key]:
				if config.settings['to_train'][comp]:
					to_train.append({'params': network.components[comp].parameters(), 'lr':config.settings['lr']})#, 'momentum':0.1, 'nesterov':True, 'weight_decay':0.1})
			optimizer[key] = optim.Adam(params = to_train)   #优化器初始化

	# ====== CALL TRAINING AND VALIDATION PROCESS ======
	trainval(network, optimizer, exp_name, index_lists, config.settings)

def trainval(network, optimizer, exp_name, index_lists, settings):

	global least_val_loss
	global itt_delete

	train_iter = config.settings['start_iter']
	
	#模型各种信息初始化
	trainer_G = TrainerG(network, optimizer, exp_name, index_lists, settings)

	train_acc_list = []

	while True:

		print ("\n----------- train_iter " + str(train_iter) + ' -----------\n')
		trainer_G.set_mode_train()
		acc_gen = trainer_G.train()
		trainer_G.log_errors('train')
		train_acc_list.append(acc_gen.data.cpu().numpy())

		if train_iter%config.settings['val_after'] == 0:  

			print('validating') 

			trainer_G.set_mode_val()
			min_val_flag=test(trainer_G)

			print('min_val_flag', min_val_flag)

			if(min_val_flag):
				print ("Saving - iteration", train_iter)
				dict_to_save = {component:network.components[component].cpu().state_dict() for component in network.components}
				torch.save(dict_to_save, os.path.join(os.path.join(config.settings['weights_path'],exp_name)+'/', 'best_' + str(train_iter) + '.pth'))
				network.cuda()
				itt_delete.append(train_iter)
				if(len(itt_delete)>100):
					for k in itt_delete[:-100]:
						subprocess.call(['rm', os.path.join(os.path.join(config.settings['weights_path'],exp_name)+'/', 'best_' + str(k) + '.pth')])
					itt_delete = itt_delete[-100:]

			if train_iter > settings['max_iter']:
				break

		train_iter += 1 

	print(train_acc_list[settings['max_iter']])


def test(trainer_G, iteration=None): 
	global max_val_source_acc

	summary_dict=trainer_G.val_over_val_set()
	
	print('source set validation')
	print(summary_dict)
	val_acc_source = summary_dict['acc/source_avg']
	max_val_source_acc = max(val_acc_source,max_val_source_acc)
	trainer_G.log_errors('val')

	if( (max_val_source_acc==val_acc_source) ):
		return True
	else:
		return False

	
if __name__ == '__main__':
	main()



