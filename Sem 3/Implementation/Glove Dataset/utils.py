from tqdm import tqdm
import unicodedata
from sklearn.metrics.pairwise import euclidean_distances
import numpy as np
import csv
import numpy as np

def word_normalize(text):
    """Resolve different type of unicode encodings."""
    return unicodedata.normalize('NFD', text)

def cal_euclidean_distances(word_embed_1, word_embed_2):
    distance = euclidean_distances(word_embed_1, word_embed_2)
    return distance

gloveFilePath = "glove.840B.300d.txt"

num_lines = sum(1 for _ in open(gloveFilePath, encoding="utf8"))

oneNumLines = 244002
