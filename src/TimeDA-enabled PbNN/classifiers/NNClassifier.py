import time,os
from typing import Tuple, List, Union, Dict, Counter
import pickle
import numpy as np
import pandas as pd
import torch
from torch import optim, nn
from torch.utils.data import DataLoader

from classifiers.BaseClassifier import BaseClassifier, ClassificationResult, compute_classification_result
from classifiers.config import Config
from model.ProjectClassifier import ProjectClassifier
from preprocessing.context_split import ContextSplit
from util import ProcessedFolder, ProcessedSnapshotFolder
import model.config_supervised as config_supervised

import subprocess
max_val_source_acc = -10000
max_val_acc = -10000
itt_delete = []

class NNClassifier(BaseClassifier):
    def __init__(self, config: Config, project_folder: ProcessedFolder, change_entities: pd.Series,
                 change_to_time_bucket: Dict, min_max_count: Tuple[int, int], author_occurrences: Counter,
                 context_splits: List[ContextSplit]):
        super(NNClassifier, self).__init__(config, project_folder, change_entities, change_to_time_bucket,
                                           min_max_count, author_occurrences, context_splits)

    def __sample_loaders(self, fold_ind: Union[int, Tuple[int, int]] = 0) -> Tuple[DataLoader, DataLoader]:
        '''
        The function creates a train and test loader for the given fold.
        
        :param self: This is the object that is being called
        :param fold_ind: The index of the fold to use, defaults to 0
        :type fold_ind: Union[int, Tuple[int, int]] (optional)
        :param is_epoch_attack: If True, the attack is performed on the whole dataset, defaults to False
        (optional)
        :param batch_size: The batch size to use for training
        :return: The train_loader and test_loader.
        '''
        train_dataset, test_dataset = self._split_train_test(self._loader, fold_ind, pad=True)
        original_labels = self._loader.original_labels()
        train_loader=[]
        if self.config.final_test() == 0:
            train_loader = DataLoader(train_dataset, self.config.batch_size(), shuffle=True, num_workers=1)
        test_loader = DataLoader(test_dataset, self.config.batch_size(), shuffle=True, num_workers=1)
        return train_loader, test_loader, original_labels
        
    def repair_labels(self,labels,train_original_labels):
        '''
        The function is used to repair the labels of the test set.
            The labels of the test set are not in the same order as the labels of the train set.
            So we need to repair the labels of the test set.
        
        :param self: the instance of the class
        :param labels: the predicted labels
        :param train_original_labels: the original labels of the training set
        :param cur_original_labels: the original labels of the current batch
        :return: The labels are being returned as a tensor.
        '''
        labels_list = labels.numpy().tolist()
        original_labels = self._loader.original_labels()
        print(labels_list)
        print(original_labels)
        result = []
        for i in labels_list:
            result.append(train_original_labels.index(original_labels[i]))
        
        result = torch.LongTensor(result)
        print(result)
        return result

    def print_file_name(self,predictions,train_original_labels):
        index = 0
        original_labels = self._loader.original_labels()
        for author_name in original_labels:
            author_files_dir = os.path.join(self.data_files_dir,author_name)
            for author_files in os.listdir(author_files_dir):
                prediction_author = train_original_labels[int(predictions[index])]
                if author_name == prediction_author:
                    file_path=os.path.join(author_files_dir,author_files)
                else:
                    file_path=os.path.join(author_files_dir,author_files)
                index += 1

    def tmp_loder(self, path):
        change_entities = None
        author_occurrences = None
        change_to_time_bucket = None
        context_splits = None
        fold_ind=0
        project_folder_tmp = ProcessedSnapshotFolder(path)
        classifier_tmp = NNClassifier(self.config, project_folder_tmp, change_entities, change_to_time_bucket,
                        self.config.min_max_count(), author_occurrences, context_splits)        
        train_loader_tmp, test_loaders_tmp, original_labels_tem = classifier_tmp.__sample_loaders(fold_ind)    
        return train_loader_tmp, test_loaders_tmp, original_labels_tem

    def __train(self, train_loader, test_loaders, model, optimizer, loss_function, n_epochs, log_batches, batch_size,
                fold_ind, should_train, train_original_labels):
        print("Start training")
        accuracies = [ClassificationResult(0, 0, 0, 0) for _ in range(len(test_loaders))]
        if not should_train:
            n_epochs = 1
        for epoch in range(n_epochs):

            print("Epoch #{}".format(epoch + 1))
            
            if should_train:
                model.train()
                current_loss = 0
                start_time = time.time()
                for n_batch, sample in enumerate(train_loader):
                    starts, paths, ends, labels = sample['starts'], sample['paths'], sample['ends'], sample['labels']
                    optimizer.zero_grad()
                    predictions = model((starts, paths, ends))
                    loss = loss_function(predictions, labels)
                    loss.backward()
                    optimizer.step()

                    current_loss += loss.item()
                    if (n_batch + 1) % log_batches == 0:
                        print("After {} batches: average loss {}".format(n_batch + 1, current_loss / log_batches))
                        print(f"Throughput {int(log_batches * batch_size / (time.time() - start_time))} examples / sec")
                        current_loss = 0
                        start_time = time.time()

                model.eval()
            with torch.no_grad():
                for i, test_loader in enumerate(test_loaders):
                    total = len(test_loader.dataset)
                    predictions = np.zeros(total)
                    targets = np.zeros(total)
                    cur = 0
                    test_loss = 0.
                    n_batches = 0
                    for sample in test_loader:
                        starts, paths, ends, labels = sample['starts'], sample['paths'], sample['ends'], sample['labels']               
                        if self.config.final_test() == 1:
                            labels = self.repair_labels(labels,train_original_labels.tolist())
                        batched_predictions = model((starts, paths, ends))
                        test_loss += loss_function(batched_predictions, labels)
                        n_batches += 1
                        batched_predictions = np.argmax(batched_predictions, axis=1)
                        batched_targets = labels
                        predictions[cur:cur + len(batched_predictions)] = batched_predictions
                        targets[cur:cur + len(batched_targets)] = batched_targets
                        cur += len(batched_predictions)
                    print("average loss {}".format(test_loss / n_batches))
                    classification_result = compute_classification_result(targets, predictions, fold_ind)
                    print(f"classification results: {classification_result}")
                    accuracies[i] = max(accuracies[i], classification_result, key=lambda cl: cl.accuracy)
        print("Training completed")
        return accuracies

    def __run_classifier(self, fold_ind, stage) \
            -> Union[float, List[float]]:
        global itt_delete
        if fold_ind not in self.models:            
            model = ProjectClassifier(100000,
                                      100000,
                                      256,
                                      n_classes=20)
            model=model.to(config_supervised.settings['device'])
            should_train = True
            if -1 in self.models:
                print("replace vectorization")
                model=self.models[-1]
        else:
            model = self.models[fold_ind]
            should_train = False

        optimizer={}
        if(stage=="supervised"):    
            for key in config_supervised.settings['use_loss']:
                if config_supervised.settings['use_loss'][key]:
                    to_train = []
                    for comp in config_supervised.settings['optimizer'][key]:
                        if config_supervised.settings['to_train'][comp]:
                            to_train.append({'params': model.components[comp].parameters(), 'lr':config_supervised.settings['lr']})#, 'momentum':0.1, 'nesterov':True, 'weight_decay':0.1})
                    optimizer[key] = optim.Adam(params = to_train)


            exp_name = config_supervised.settings['exp_name']
            train_iter = config_supervised.settings['start_iter']
            from model.Trainer_supervised import TrainerG
            source_data_path="/home/zss/data/project5/nn_DA/processed/gcj_cpp_12_18/gcj2012/cpp/"
            project_folder = ProcessedSnapshotFolder(source_data_path)
            trainer_G = TrainerG(self.config, model, project_folder, self.config.min_max_count(),model, optimizer, exp_name, config_supervised.settings)
            train_acc_list = []
            while True:
                print ("\n----------- train_iter " + str(train_iter) + ' -----------\n')
                trainer_G.set_mode_train(model)
                acc_gen = trainer_G.train(model)
                trainer_G.log_errors('train')
                train_acc_list.append(acc_gen.data.cpu().numpy())
                if train_iter%config_supervised.settings['val_after'] == 0:  
                    print('validating')
                    trainer_G.set_mode_val(model)
                    min_val_flag=self.test(trainer_G,model)
                    if(min_val_flag):
                        print ("Saving - iteration", train_iter)
                        dict_to_save = {component:model.components[component].cpu().state_dict() for component in model.components}
                        torch.save(dict_to_save, os.path.join(os.path.join(config_supervised.settings['weights_path'],exp_name)+'/', 'best_' + str(train_iter) + '.pth'))
                        model.cuda()
                        itt_delete.append(train_iter)
                        if(len(itt_delete)>100):
                            for k in itt_delete[:-100]:
                                subprocess.call(['rm', os.path.join(os.path.join(config_supervised.settings['weights_path'],exp_name)+'/', 'best_' + str(k) + '.pth')])
                            itt_delete = itt_delete[-100:]
                    if train_iter > config_supervised.settings['max_iter']:
                        break
                train_iter += 1 
        else:
            import model.config_adapt as config_adapt
            if config_adapt.settings['load_weights']:
                dict_to_load = torch.load(config_adapt.settings['load_weights_path'])
                for component in dict_to_load:			
                    model.components[component].load_state_dict(dict_to_load[component])
            exp_name = config_adapt.settings['exp_name']
            # Initialize weights from source networks if we are loading from supervised experiment
            if config_adapt.settings['load_exp_name'].split('_')[-1] != 'adapt':
		        # Initialize Ft from Fs
                model.components['M'].load_state_dict(model.components['M'].state_dict())
                model.components['Ft'].load_state_dict(model.components['Fs'].state_dict())
                model.components['Cs'].load_state_dict(model.components['Cs'].state_dict())
                model.components['Cn'].load_state_dict(model.components['Cn'].state_dict())
		
	        # ====== DEFINE OPTIMIZERS ======

            for key in config_adapt.settings['use_loss']:
                if config_adapt.settings['use_loss'][key]:
                    to_train = []
                    for comp in config_adapt.settings['optimizer'][key]:
                        if config_adapt.settings['to_train'][comp]:
                            to_train.append({'params': model.components[comp].parameters(), 'lr':config_adapt.settings['lr']})
                    optimizer[key] = optim.Adam(params = to_train)
            train_iter = config_adapt.settings['start_iter']
            from model.Trainer_adapt import TrainerG
            source_data_path="/home/zss/data/project5/nn_DA/processed/gcj_cpp/gcj2014/cpp/"
            project_folder = ProcessedSnapshotFolder(source_data_path)
            trainer_G = TrainerG(self.config, model, project_folder, self.config.min_max_count(),model, optimizer, exp_name, config_adapt.settings)            
            train_acc_list = []
            while True:
                print ("\n----------- train_iter " + str(train_iter) + ' -----------\n')
                trainer_G.set_mode_train(model)
                acc_gen = trainer_G.train(model)
                trainer_G.log_errors('train')
                train_acc_list.append(acc_gen.data.cpu().numpy())
                if train_iter%config_adapt.settings['val_after'] == 0:  
                    print('validating') 
                    trainer_G.set_mode_val(model)
                    min_val_flag=self.test_adapt(trainer_G,model)
                    print('min_val_flag', min_val_flag)
                    if(min_val_flag):
                        print ("Saving - iteration", train_iter)
                        dict_to_save = {component:model.components[component].cpu().state_dict() for component in model.components}
                        torch.save(dict_to_save, os.path.join(os.path.join(config_adapt.settings['weights_path'],exp_name)+'/', 'best_' + str(train_iter) + '.pth'))
                        model.cuda()
                        itt_delete.append(train_iter)
                        if(len(itt_delete)>10):
                            for k in itt_delete[:-10]:
                                subprocess.call(['rm', os.path.join(os.path.join(config_adapt.settings['weights_path'],exp_name)+'/', 'best_' + str(k) + '.pth')])
                            itt_delete = itt_delete[-10:]
                    if train_iter > config_adapt.settings['max_iter']:
                        break
                train_iter += 1 
            print(train_acc_list[config_adapt.settings['max_iter']])

        if fold_ind not in self.models:
            self.models[fold_ind] = model

    def test(self,trainer_G, model,iteration=None): 
        global max_val_source_acc
        summary_dict=trainer_G.val_over_val_set(model)
        
        print('source set validation')
        print(summary_dict)
        val_acc_source = summary_dict['acc/source_avg']
        print(val_acc_source)
        max_val_source_acc = max(val_acc_source,max_val_source_acc)
        trainer_G.log_errors('val')

        if( (max_val_source_acc==val_acc_source) ):
            return True
        else:
            return False

    def test_adapt(self,trainer_G, model,target=False, iteration=None): 
        global max_val_acc
        val_record=trainer_G.val_over_val_set(model)
        print(val_record, max_val_acc)
        print('source set validation')
        print(val_record)
        val_acc = val_record
        max_val_acc=max(val_acc,max_val_acc)
        trainer_G.log_errors('val')
        if(max_val_acc==val_acc):
            return True
        else:
            return False

    def run(self, fold_indices: Union[List[int], List[Tuple[int, int]]], train_original_labels, stage) \
            -> Tuple[float, float, List[ClassificationResult]]:
        print("Begin cross validation")
        print("train_original_labels")
        print(train_original_labels)
        scores = []
        for fold_ind in fold_indices:
            scores.append(self.__run_classifier(fold_ind, stage))
            print(scores[-1])
        print("scores")
        print(scores)
        return self._loader.original_labels()
