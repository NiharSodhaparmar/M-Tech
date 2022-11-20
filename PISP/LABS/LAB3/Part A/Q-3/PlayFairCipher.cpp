#include <iostream>
#include <fstream>
using namespace std;

struct node
{
    int i;
    int j;
};

string plainTextPreProcess(string plainText)
{
    string finalPlainText = "", tempPlainText = "";

    // removing space & replace J with I
    for (int i = 0; i < plainText.length(); i++)
    {
        if (plainText[i] >= 'a' && plainText[i] <= 'z' || plainText[i] >= 'A' && plainText[i] <= 'Z')
        {
            if (toupper(plainText[i]) == 'J')
                tempPlainText += 'I';
            else
                tempPlainText += plainText[i];
        }
    }

    for (int i = 0; i < tempPlainText.length(); i += 2)
    {
        if (tempPlainText[i] == tempPlainText[i + 1])
        {
            finalPlainText += toupper(tempPlainText[i]);
            finalPlainText += 'X';
            i--;
        }
        else
        {
            if (i == tempPlainText.length() - 1)
            {
                finalPlainText += toupper(tempPlainText[i]);
                finalPlainText += 'X';
            }
            else
            {
                finalPlainText += toupper(tempPlainText[i]);
                finalPlainText += toupper(tempPlainText[i + 1]);
            }
        }
    }
    return finalPlainText;
}

string keyPreProcess(string k)
{
    string key = "";
    for (int i = 0; i < k.length(); i++)
    {
        if (k[i] != ' ')
        {
            if (toupper(k[i]) == 'J')
                key += 'I';
            else
                key += toupper(k[i]);
        }
    }
    return key;
}

struct node search(char a[5][5], char p)
{
    struct node l = {0, 0};
    for (int u = 0; u < 5; u++)
    {
        for (int v = 0; v < 5; v++)
        {
            if (a[u][v] == p)
            {
                l.i = u;
                l.j = v;
                return l;
            }
        }
    }

    return l;
}

string encryption(string pt, string key)
{
    // step1: creation of 5x5 playfair matrix
    char playFairMatrix[5][5];
    bool visited[26] = {0};

    int row = 0, col = 0;
    // step1.1: creating matrix for keyword
    for (int i = 0; i < key.length(); i++)
    {
        if (visited[key[i] - 65] == 0)
        {
            playFairMatrix[row][col] = key[i];
            visited[key[i] - 65] = 1;

            if (col + 1 < 5)
                col++;
            else
            {
                row++;
                col = 0;
            }
        }
    }

    // step1.2: creating matrix for leftover words
    for (char t = 'A'; t <= 'Z'; t++)
    {
        if (t != 'J')
        {
            if (visited[t - 65] == 0)
            {
                playFairMatrix[row][col] = t;
                visited[t - 65] = 1;
                if (col + 1 < 5)
                    col++;
                else
                {
                    col = 0;
                    row++;
                }
            }
        }
    }

    cout << "Play Fair Matrix: " << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << playFairMatrix[i][j] << " ";
        }
        cout << endl;
    }

    // step2: encrypt the plain text
    string ct = "";

    for (int r = 0; r < pt.length(); r = r + 2)
    {
        struct node x = search(playFairMatrix, pt[r]);
        struct node y = search(playFairMatrix, pt[r + 1]);
        // if same row
        if (x.i == y.i)
        {
            ct = ct + playFairMatrix[x.i][((x.j) + 1) % 5];
            ct = ct + playFairMatrix[y.i][((y.j) + 1) % 5];
        }
        // if same col
        else if (x.j == y.j)
        {
            ct = ct + playFairMatrix[((x.i) + 1) % 5][x.j];
            ct = ct + playFairMatrix[((y.i) + 1) % 5][y.j];
        }
        // diagonal
        else
        {
            ct = ct + playFairMatrix[x.i][y.j];
            ct = ct + playFairMatrix[y.i][x.j];
        }
    }
    // step3: return cipher text
    return ct;
}

int main()
{
    ifstream inputPlainText("./PlainText.txt");
    ifstream inputKey("./key.txt");

    string plainText, cipherText, line, key;

    while (getline(inputPlainText, line))
    {
        plainText += line + '\n';
    }

    while (getline(inputKey, line))
    {
        key += line + '\n';
    }

    cout << endl;
    plainText = plainTextPreProcess(plainText);
    cout << "Plain Text: " << endl;
    cout << plainText << endl;

    cout << endl;
    key = keyPreProcess(key);
    cout << "Key: " << key << endl;

    cipherText = encryption(plainText, key);
    cout << endl;
    cout << "Cipher Text: " << endl;
    cout << cipherText << endl;
    cout << endl;
}