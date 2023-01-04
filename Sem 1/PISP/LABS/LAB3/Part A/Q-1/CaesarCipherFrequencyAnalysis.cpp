#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

pair<char, int> findEntryWithLargestValue(map<char, int> sampleMap)
{
    pair<char, int> entryWithMaxValue = make_pair('A', 0);

    map<char, int>::iterator currentEntry;
    for (currentEntry = sampleMap.begin(); currentEntry != sampleMap.end(); ++currentEntry)
    {
        if (currentEntry->second > entryWithMaxValue.second)
        {
            entryWithMaxValue = make_pair(currentEntry->first, currentEntry->second);
        }
    }
    return entryWithMaxValue;
}

string decrypt(string cipherText, int key)
{
    string plainText;

    for (int i = 0; i < cipherText.length(); i++)
    {
        if (cipherText[i] >= 'a' && cipherText[i] <= 'z')
        {
            int temp = cipherText[i] - 'a' - key;
            plainText += char(((temp < 0 ? temp + 26 : temp) % 26) + 'a');
        }
        else if (cipherText[i] >= 'A' && cipherText[i] <= 'Z')
        {
            int temp = cipherText[i] - 'A' - key;
            plainText += char(((temp < 0 ? temp + 26 : temp) % 26) + 'A');
        }
        else
        {
            plainText += cipherText[i];
        }
    }

    return plainText;
}

int main()
{
    ifstream input("./CipherText.txt");
    string line, cipherText;
    map<char, int> map;

    while (getline(input, line))
    {
        cipherText += line + '\n';
    }

    for (int i = 0; i < cipherText.size(); i++)
    {
        char ch = cipherText[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
            map[tolower(ch)]++;
    }

    for (auto x : map)
        cout << x.first << " " << x.second << endl;

    pair<char, int> a = findEntryWithLargestValue(map);
    cout << endl
         << a.first << " occured " << a.second << " times in cipher text, which is highest." << endl;

    vector<char> freqChars = {'e', 't', 'a', 'i', 'o'};

    for (int i = 0; i < freqChars.size(); i++)
    {
        int key = a.first - freqChars[i];
        cout << "----------------------------------------------------------------------------" << endl;
        cout << "Possible key : " << key << endl;
        cout << endl;

        string plainText = decrypt(cipherText, key);
        cout << plainText << endl;
        cout << "----------------------------------------------------------------------------" << endl;
        cout << endl;
    }

    return 0;
}
