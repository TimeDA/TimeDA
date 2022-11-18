import argparse
import os,glob

import yaml
import pickle
from classifiers.BaseClassifier import ClassificationResult
from classifiers.CaliskanClassifier import CaliskanClassifier
from classifiers.NNClassifier import NNClassifier
from classifiers.RFClassifier import RFClassifier
from classifiers.config import Config
from preprocessing.compute_occurrences import compute_occurrences
from preprocessing.context_split import context_split
from preprocessing.resolve_entities import resolve_entities
from preprocessing.time_split import time_split
from util import ProcessedFolder, ProcessedSnapshotFolder
from pathlib import Path
import model.config_supervised as config_supervised
import torch
import subprocess


data_files_dir = "/home/zss/data/project5/nn_DA/datasets/java_12_18/gcj2018"
g_modelfile="/home/zss/data/project5/nn_DA/attribution/authorship_pipeline/nn_output/DA_cpp12_18/train_10/"


def output_filename(input_file):

    if not os.path.exists('output'):
        os.mkdir('output')
    return 'output/' + input_file

def output_file(input_file):
    output_file = output_filename(input_file)
    if not os.path.exists(os.path.dirname(output_file)):
        os.makedirs(os.path.dirname(output_file))
    return open(output_file, 'w')

def main(args):
    stage="supervised"  #supervised or adapt
    if (stage=="supervised"):
        # ====== DELETE PAST RUNS ======
        torch.cuda.set_device(config_supervised.settings['gpu'])
        exp_name = config_supervised.settings['exp_name']
        subprocess.call(["rm", "-rf", os.path.join(config_supervised.settings['weights_path'],exp_name)])
        subprocess.call(["mkdir", os.path.join(config_supervised.settings['weights_path'],exp_name)])
        subprocess.call(["rm", "-rf", os.path.join(config_supervised.settings['summaries_path'],exp_name)])
        subprocess.call(["mkdir", os.path.join(config_supervised.settings['summaries_path'],exp_name)])
        subprocess.call(["mkdir", os.path.join(config_supervised.settings['summaries_path'],exp_name)+"/logdir_train"])
        subprocess.call(["mkdir", os.path.join(config_supervised.settings['summaries_path'],exp_name)+"/logdir_val"])
    else:
        import model.config_adapt as config_adapt
        exp_name = config_adapt.settings['exp_name']
        subprocess.call(["rm", "-rf", os.path.join(config_adapt.settings['weights_path'],exp_name)])
        subprocess.call(["mkdir", os.path.join(config_adapt.settings['weights_path'],exp_name)])
        subprocess.call(["rm", "-rf", os.path.join(config_adapt.settings['summaries_path'],exp_name)])
        subprocess.call(["mkdir", os.path.join(config_adapt.settings['summaries_path'],exp_name)])
        subprocess.call(["mkdir", os.path.join(config_adapt.settings['summaries_path'],exp_name)+"/logdir_train"])
        subprocess.call(["mkdir", os.path.join(config_adapt.settings['summaries_path'],exp_name)+"/logdir_val"])
    
    global g_modelfile
    config = Config.fromyaml(args.config_file)

    if config.mode() == 'snapshot':
        project_folder = ProcessedSnapshotFolder(config.source_data_path())
        change_entities = None
        author_occurrences = None
    else:
        project_folder = ProcessedFolder(config.source_folder())
        change_entities = resolve_entities(project_folder)
        author_occurrences, _, _, _ = compute_occurrences(project_folder)

    if config.mode() == 'time':
        change_to_time_bucket = time_split(project_folder, config.time_folds(), uniform_distribution=True)
    else:
        change_to_time_bucket = None
    if config.mode() == 'context':
        context_splits = context_split(project_folder, *config.min_max_count(), *config.min_max_train())
    else:
        context_splits = None
    if config.classifier_type() == 'nn':
        classifier = NNClassifier(config, project_folder, change_entities, change_to_time_bucket,
                                  config.min_max_count(), author_occurrences, context_splits)
    elif config.classifier_type() == 'rf':
        classifier = RFClassifier(config, project_folder, change_entities, change_to_time_bucket,
                                  config.min_max_count(), author_occurrences, context_splits)
    elif config.classifier_type() == 'caliskan':
        classifier = CaliskanClassifier(config, project_folder, change_entities, change_to_time_bucket,
                                        config.min_max_count(), context_splits)
    else:
        raise ValueError('Classifier type should be set in config')

    if config.mode() == 'time':
        fold_indices = [(i, j) for i in range(config.time_folds()) for j in range(i + 1, config.time_folds())]
    elif config.mode() == 'context':
        fold_indices = [i for i in range(len(context_splits))]
    else:
        fold_indices = [0]
    train_original_labels = []
    
    classifier.data_files_dir = data_files_dir
    skip_read_write = True if classifier.config.skip_read_write()==1 else False
    isModelExist = False
    
    if not skip_read_write:
        train_original_labels = []
        if Path(g_modelfile+"0.pck").exists():
            isModelExist = True
        if (stage!="supervised") and isModelExist:
                modelfile = g_modelfile + "0.pck"
                print("Loading model --> "+modelfile)
                classifier.models[-1] = pickle.load(open(modelfile, 'rb'))

    original_labels = classifier.run(fold_indices,train_original_labels,stage)
    print(original_labels)

    if not isModelExist and not skip_read_write and stage=="supervised":
        for fold_ind in fold_indices:
            modelfile = g_modelfile + str(fold_ind)+".pck"
            print("Save label --> "+modelfile)
            pickle.dump(classifier.models[fold_ind], file=open(modelfile, 'wb'))

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument(dest='config_file', type=str, help='Configuration file in YAML format')
    args = parser.parse_args()
    main(args)
