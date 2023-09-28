from tqdm import tqdm
import unicodedata
from sklearn.metrics.pairwise import euclidean_distances
import numpy as np
from csv import writer
import numpy as np

def word_normalize(text):
    """Resolve different type of unicode encodings."""
    return unicodedata.normalize('NFD', text)

def cal_euclidean_distances(word_embed_1, word_embed_2):
    distance = euclidean_distances(word_embed_1, word_embed_2)
    return distance

gloveFilePath = "glove.840B.300d.txt"

num_lines = sum(1 for _ in open(gloveFilePath, encoding="utf8"))

all_count = 0
word2id = {}
all_word_embed=[]

with open(gloveFilePath, encoding="utf8") as f:
    line = f.readline().rstrip().split(' ')

    if len(line) != 2:
        f.seek(0)
    for row in tqdm(f, total=num_lines - 1):
        content = row.rstrip().split(' ')

        cur_word=word_normalize(content[0])
        word2id[cur_word] = all_count
        all_count += 1

        emb=[float(i) for i in content[1:]]
        all_word_embed.append(emb)

    # print("all_word_embed")
    # print(all_word_embed)

    id2word = {v: k for k, v in word2id.items()}

    # print("id2word")
    # print(id2word)

    for i in tqdm(range(len(all_word_embed))):
        distances = cal_euclidean_distances([all_word_embed[i]], all_word_embed)

        currSynonyms = [id2word[i]]
        # currSynonyms = []

        top11 = np.argsort(distances)[0][:11]
        # print("len top11")
        # print(len(top11))
        # print(top11)

        # print("###################################")
        # print(distances)
        # print(top10)
        # print("curr word: ", id2word[i])
        
        for j in top11:
            # print(j)
            # print(id2word[j])
            currSynonyms.append(id2word[j])

        # print("currSynonyms")
        # print(len(currSynonyms))
        # print(currSynonyms)

        with open('synonym_words.csv', 'a', newline='') as f:
 
            # Pass this file object to csv.writer()
            # and get a writer object
            writer_object = writer(f)
        
            # Pass the list as an argument into
            # the writerow()
            writer_object.writerow(currSynonyms)
        
            # Close the file object
            f.close()


        
        # print(distances)
        # distances = cal_euclidean_distances()

    # distances = cal_euclidean_distances(all_word_embed, all_word_embed)

    # print("#######-----------------------------------------------------------#######")
    # print("word2id")
    # print(word2id)

    # print("#######-----------------------------------------------------------#######")
    # print("distances")
    # print(distances)

    # print("#######-----------------------------------------------------------#######")
    # print("id2word")
    # print(id2word)

    # synonymWords = []

    # for i in range(len(distances)):
        # top5 = np.argsort(distances[i])[::-1][-10:]
        # print(top5)

        # currSynonyms = [id2word[i]]

        # print("#######-----------------------------------------------------------#######")
        # print("Curr Word: ", id2word[i])
        # print("Simillar Top 5 Words")

        # for j in reversed(top5):
            # print(id2word[j])
        #     currSynonyms.append(id2word[j])

        # synonymWords.append(currSynonyms)

    # with open('synonym_words.csv', 'w', encoding='UTF8', newline='') as f:
    #     writer = csv.writer(f)

    #     # write multiple rows
    #     writer.writerows(synonymWords)






# print("all_word_embed")
# print(all_word_embed)
# Unable to allocate 4.91 GiB for an array with shape (2196018, 300) and data type float64