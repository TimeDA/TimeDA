from model.CodeVectorizer import CodeVectorizer
import numpy as np
import torch
vectorization=CodeVectorizer(20000, 20000, 256)

def CodeToVec(code):
    vec=vectorization(code)
    return vec
