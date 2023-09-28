import csv

header = ['word', 'synonym words']

words = [ ['girls', 'girls1', 'girls2'],
          ['girls', 'girls1', 'girls2']]


with open('extracted_strong_words.csv', 'w', encoding='UTF8', newline='') as f:
    writer = csv.writer(f)

    # write the header
    writer.writerow(header)

    # write multiple rows
    writer.writerows(words)