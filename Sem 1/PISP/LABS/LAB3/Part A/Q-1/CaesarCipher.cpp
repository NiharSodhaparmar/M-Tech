#include <iostream>
#include <fstream>
using namespace std;

string encrypt(string plainText, int key)
{
    string cipherText;

    for (int i = 0; i < plainText.length(); i++)
    {
        if (plainText[i] >= 'a' && plainText[i] <= 'z')
        {
            cipherText += char(((plainText[i] - 'a' + key) % 26) + 'a');
        }
        else if (plainText[i] >= 'A' && plainText[i] <= 'Z')
        {
            cipherText += char(((plainText[i] - 'A' + key) % 26) + 'A');
        }
        else
        {
            cipherText += plainText[i];
        }
    }

    return cipherText;
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
    ifstream input("./PlainText.txt");
    ofstream output("./CipherText.txt");

    string plainText, cipherText, line, decryptedText;
    int key = 15;

    while (getline(input, line))
    {
        plainText += line + '\n';
    }

    cout << "Plain Text: " << endl;
    for (int i = 0; i < plainText.length(); i++)
    {
        cout << plainText[i];
    }
    cout << endl;

    cipherText = encrypt(plainText, key);

    cout << "Cipher Text: " << endl;
    for (int i = 0; i < cipherText.length(); i++)
    {
        cout << cipherText[i];
    }
    cout << endl;

    output << cipherText;

    decryptedText = decrypt(cipherText, key);

    cout << "Decrypt Text: " << endl;
    for (int i = 0; i < cipherText.length(); i++)
    {
        cout << decryptedText[i];
    }
    cout << endl;
}