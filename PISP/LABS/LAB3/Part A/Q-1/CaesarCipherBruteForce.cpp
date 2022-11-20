#include <iostream>
#include <fstream>
using namespace std;

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
    string cipherText, line, decryptedText;

    while (getline(input, line))
    {
        cipherText += line + '\n';
    }

    for (int i = 1; i < 26; i++)
    {
        decryptedText = decrypt(cipherText, i);

        cout << "----------------------------------------------------------------------------" << endl;
        cout << "Decrypted Message for key " << i << endl;
        cout << endl;
        cout << decryptedText << endl;
        cout << "----------------------------------------------------------------------------" << endl;
        cout << endl;
    }
}