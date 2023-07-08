#from nltk.corpus import stopwords
from bs4 import BeautifulSoup
import requests

def get_soup_object(url):
    if not(url.startswith("http")):
        url="https://"+url
    requests_obj=requests.get(url).text
    soup = BeautifulSoup(requests_obj, 'html.parser')
    #print("get_soup_object  done")
    return soup

def remove_garbage(soup):
    for s in soup.select("style"):
        s.extract()
    for s in soup.select('script'):
        s.extract()
    #print("remove_garbage done")
    return soup
    
def get_text(soup):
    text=soup.get_text()
    text_list=text.splitlines(True)
    text_without_blank_line=""
    for line in text_list:
        if len(line)>1:
            text_without_blank_line += str(line)
    only_text_list = text_without_blank_line.split()
    #print("get_text done")
    return only_text_list

def make_list_with_lower_case_string(text_list):
    for i in range(len(text_list)):
        text_list[i]=text_list[i].lower()
    #print("make_list_with_lower_case_string done")
    return text_list

'''
def get_stopword_from_nltk():
    stop_word=stopwords.words('english')
    print("get_stopword_from_nltk done")
    return stop_word
'''


def get_stopword_from_file():
    stop_word=[]
    with open("stop_words.txt") as file:
        for i in file:
            stop_word.append(i.lower().strip())
    #print("get_stopword_from_file done")
    return stop_word


def remove_stopword(stop_word,text_list):
    for i in stop_word:
        while True:
            try:
                text_list.remove(i)
            except :
                break
    #print("remove_stopword done")
    return text_list

def count_word_frequency(text_list):
    count_frequency={}
    for i in text_list:
        count_frequency[i]=count_frequency.get(i,0)+1
    #print("count_word_frequency done")
    return count_frequency

def sort_frequency_count(count_frequency):
    sort_list=sorted(count_frequency.items(),reverse=True, key = lambda kv:(kv[1], kv[0]))
    sorted_dict={}
    for i in sort_list:
        sorted_dict[i[0]]=i[1]
    #print("sort_frequency_count done")
    return sorted_dict


url=input("Enter url : ")
soup = get_soup_object(url)
soup = remove_garbage(soup)
only_text_list = get_text(soup)
lower_case_text_list = make_list_with_lower_case_string(only_text_list)
stop_word = get_stopword_from_file()
text_list = remove_stopword(stop_word,lower_case_text_list)
count_frequency = count_word_frequency(text_list)
sort_list = sort_frequency_count(count_frequency)
#print(count_frequency)
print(sort_list)
