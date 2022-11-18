import os

from keras.utils import Sequence
import sys
import importlib
import copy
import subprocess
import numpy as np
import pickle
import json
import shutil
import psutil
import threading
import multiprocessing
from concurrent.futures import ThreadPoolExecutor, ProcessPoolExecutor

from featureextractionV2.StyloFeaturesProxy import StyloFeaturesProxy
from featureextractionV2.StyloFeatures import StyloFeatures
from featureextractionV2.StyloUnigramFeatures import StyloUnigramFeatures
from classification import StratifiedKFoldProblemId
from featureextractionV2 import utils_extraction
from classification.NovelAPI.Learning import Learning

from timeit import default_timer as timer

from keras import backend as K
import tensorflow as tf
from keras.models import load_model
from keras.losses import categorical_crossentropy
from sklearn.metrics import log_loss

from keras.utils import to_categorical

from ConfigurationLearning.ConfigurationLearningRNN import ConfigurationLearningRNN
import ConfigurationGlobalLearning as Config
import classification.NovelAPI.utils_classification

from distutils.dir_util import copy_tree

from for_while import trans_tree

from lxml import etree
ns = {'src': 'http://www.srcML.org/srcML/src',
    'cpp': 'http://www.srcML.org/srcML/cpp',
    'pos': 'http://www.srcML.org/srcML/position'}
doc = None

num_classes = 204
config_learning: ConfigurationLearning = ConfigurationLearning(
    repo_path=Config.repo_path,
    dataset_features_dir=os.path.join(Config.repo_path, "data/dataset_2017"),
    suffix_data="_2017_8_formatted_macrosremoved",
    learnmodelspath=Config.learnmodelspath,
    use_lexems=False,
    use_lexical_features=False,
    stop_words=Config.stop_words_codestylo,
    probsperprogrammer=Config.probsperprogrammer,
    no_of_programmers = 204,
    noofparallelthreads=8,
    scale=True,
    cv_optimize_rlf_params=False,
    cv_use_rnn_output=False,
    hyperparameters={
                      "RNN_epochs": [100, 200, 300, 350, 450, 500], #350], #50],
                      "RNN_nounits": [32, 128, 196, 256, 288], #, feature_dim],
                      "RNN_dropout": [0.6],
                      "RNN_lstmlayersno": [3],
                      "RNN_denselayersno": [3],
                      "RNN_l2reg": [0.00001],
                      "RNN_denseneurons": [0.45]
                      }
)

def save_learnsetup(modelsavedir: str, curproblem: str, learn_method: str, threshold,
                      testlearnsetup):
    """
    Small helper function to save the testlearnsetup to disk.
    """

    if modelsavedir is not None:
        modelfile = os.path.join(modelsavedir,
                                 "model_" + curproblem + "_" + learn_method + "_" + str(threshold) + ".pck")
        pickle.dump(testlearnsetup, file=open(modelfile, 'wb'))


def save_keras_model(modelsavedir: str, curproblem: str, learn_method: str, threshold,
                       keras_model, keras_hist):
    if modelsavedir is not None:
        kerasmodelpath = os.path.join(modelsavedir, "keras_model_" + curproblem
                                      + "_" + learn_method + "_" + str(threshold) + ".pck")
        keras_model.model.save(kerasmodelpath)
        if keras_hist is not None:
            histfile = os.path.join(modelsavedir, "keras_model_hist_" +
                                    curproblem + "_" + learn_method + "_" + str(threshold) + ".pck")
            pickle.dump(keras_hist, file=open(histfile, 'wb'))

class MySequence(Sequence):
    def __init__(self, trainpath, testpath, prexmlpath, batch_size=128, n=None):
        self.trainpath, self.testpath, self.prexmlpath = trainpath, testpath, prexmlpath
        self.len = sum(len(files) for _, _, files in os.walk(os.path.join(self.trainpath, '0')))
        self.batch_size = batch_size
        self.next_path = ''
        self.epoch = 0
        self.x, self.y = None, None
        self.is_checkpoint = False
        self.n = n
        self.is_kickstarted = False

    def set_model(self, model):
        self.model = model

    def set_graph(self, graph):
        self.graph = graph

    def __len__(self):
        return math.ceil(self.len / self.batch_size)

    def save_model(self, modelsavedir, curproblem):
        from classification.LearnSetups.LearnSetupRNN import LearnSetupRNN
        testlearnsetup = LearnSetupRNN(data_final_train=self.trainfiles, data_final_test=None,
                                             clf=None, rlf=None, stdscaler=self.sc)
        threshold = 800
        save_learnsetup(modelsavedir=modelsavedir, curproblem=curproblem, learn_method='RNN',
                              threshold=threshold, testlearnsetup=testlearnsetup)
        save_keras_model(modelsavedir=modelsavedir, curproblem=curproblem, learn_method='RNN',
                               threshold=threshold, keras_model=self.model, keras_hist=None)

    def make_next_dataset(self, patience=2):
        orig_train_dir = os.path.join(self.trainpath, '0')
        this_train_dir = os.path.join(self.trainpath, str(self.epoch+1))

        if self.n is not None and (self.epoch+1) % self.n == 0:
            print('Epoch ', self.epoch + 1, ' resetting training set...')
            copy_tree(orig_train_dir, this_train_dir)
            return -1

        #������һ��epoch�����ݣ��ŵ�this_train_dir��

        if self.n is None:
            self.n = 12
        print('n is now ', self.n)
        return 0

    def get_next_dataset(self):
        try:
            learning: Learning = Learning()
            threshold = 800

            stop_words_codestylo = ["txt", "in", "out", "attempt0", "attempt", "attempt1", "small", "output", "input"]
            self.next_path = os.path.join(self.trainpath, str(self.epoch))
            self.x, self.y = x_train, y_train
            return self.x, self.y
        except StopIteration:
            print('Stop!')
            return None, None

    def __getitem__(self, idx):
        if not self.is_kickstarted:
            x, y = self.get_next_dataset()
            self.is_kickstarted = True
        else:
            x, y = self.x, self.y
        batch_x = x[idx * self.batch_size:(idx + 1) * self.batch_size]
        batch_y = y[idx * self.batch_size:(idx + 1) * self.batch_size]
        return batch_x, batch_y

    def on_epoch_end(self):
        print('End of epoch==========================================', self.epoch, flush=True)
        if self.is_checkpoint:
            self.is_checkpoint = False
            save_to = os.path.join(config_learning.learnmodelspath, 'checkpoints')
            if not os.path.exists(save_to): os.makedirs(save_to)
            self.save_model(save_to, 'epoch'+str(self.epoch))

        if self.make_next_dataset() < 0:
            self.is_checkpoint = True
        self.epoch += 1
        self.get_next_dataset()
        if self.x is None:
            self.model.stop_training = True

