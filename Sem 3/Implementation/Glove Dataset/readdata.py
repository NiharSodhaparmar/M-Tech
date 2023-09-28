from tqdm import tqdm
import unicodedata

num_lines = sum(1 for _ in open("glove.840B.300d.txt", encoding="utf8"))

def word_normalize(text):
    """Resolve different type of unicode encodings."""
    return unicodedata.normalize('NFD', text)

with open("glove.840B.300d.txt", encoding="utf8") as f:
            # Skip first line if of form count/dim.
            # print("=================================================")
            # print("vocab")
            # print(vocab)
            # print("=================================================")
            line = f.readline()
            print(line)
            
            for row in tqdm(f, total=num_lines - 1):
                content = row.rstrip().split(' ')
                
                # cur_word=word_normalize(content[0])
                
                print(content)