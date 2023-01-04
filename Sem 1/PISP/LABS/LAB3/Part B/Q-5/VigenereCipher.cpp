#include <iostream>
#include <fstream>
using namespace std;

string encrypt(string plaintext, string key)
{
    string ciphertext;
    int j = 0;
    for (int i = 0; i < plaintext.size(); i++)
    {
        if ('A' <= plaintext[i] && 'Z' >= plaintext[i])
        {
            if ('A' <= key[j] && 'Z' >= key[j])
            {
                ciphertext += (((plaintext[i] - 65) + (key[j] - 65)) % 26) + 65;
            }
            else if ('a' <= key[j] && 'z' >= key[j])
            {
                ciphertext += (((plaintext[i] - 65) + (key[j] - 97)) % 26) + 65;
            }
            else
            {
                i--;
                j = (j + 1) % key.size();
                continue;
            }
            j = (j + 1) % key.size();
        }
        else if ('a' <= plaintext[i] && 'z' >= plaintext[i])
        {
            if ('A' <= key[j] && 'Z' >= key[j])
            {
                ciphertext += (((plaintext[i] - 97) + (key[j] - 65)) % 26) + 97;
            }
            else if ('a' <= key[j] && 'z' >= key[j])
            {
                ciphertext += (((plaintext[i] - 97) + (key[j] - 97)) % 26) + 97;
            }
            else
            {
                i--;
                j = (j + 1) % key.size();
                continue;
            }
            j = (j + 1) % key.size();
        }
        else
        {
            ciphertext += plaintext[i];
        }
    }
    return ciphertext;
}

string decrypt(string ciphertext, string key)
{
    string plaintext;
    int j = 0;
    for (int i = 0; i < ciphertext.size(); i++)
    {
        if ('A' <= ciphertext[i] && 'Z' >= ciphertext[i])
        {

            if ('A' <= key[j] && 'Z' >= key[j])
            {
                plaintext += (((ciphertext[i] - 65) - (key[j] - 65) + 26) % 26) + 65;
            }
            else if ('a' <= key[j] && 'z' >= key[j])
            {
                plaintext += (((ciphertext[i] - 65) - (key[j] - 97) + 26) % 26) + 65;
            }
            else
            {
                i--;
                j = (j + 1) % key.size();
                continue;
            }
            j = (j + 1) % key.size();
        }
        else if ('a' <= ciphertext[i] && 'z' >= ciphertext[i])
        {

            if ('A' <= key[j] && 'Z' >= key[j])
            {
                plaintext += (((ciphertext[i] - 97) - (key[j] - 65) + 26) % 26) + 97;
            }
            else if ('a' <= key[j] && 'z' >= key[j])
            {
                plaintext += (((ciphertext[i] - 97) - (key[j] - 97) + 26) % 26) + 97;
            }
            else
            {
                i--;
                j = (j + 1) % key.size();
                continue;
            }
            j = (j + 1) % key.size();
        }
        else
        {
            plaintext += ciphertext[i];
        }
    }
    return plaintext;
}
int main()
{
    int a;
    ifstream input;
    ofstream output;
    string line, str, key;

    cout << endl;
    cout << "Select option from below: " << endl;
    cout << "1. Encrypt" << endl;
    cout << "2. Decrypt" << endl;
    cout << endl;
    cin >> a;
    cout << endl;

    string text;

    switch (a)
    {

    case 1:
        input.open("Input.txt");
        output.open("CipherText.txt");
        while (getline(input, line))
        {
            str += line + '\n';
        }
        input.close();
        input.open("Key.txt");
        while (getline(input, line))
        {
            key += line + '\n';
        }
        text = encrypt(str, key);
        output << text;
        cout << "Input Text: " << endl;
        cout << str;
        cout << endl;
        cout << "Cipher Text: " << endl;
        cout << text;
        cout << endl;
        break;

    case 2:
        input.open("CipherText.txt");
        output.open("PlanText.txt");
        while (getline(input, line))
        {
            str += line + '\n';
        }
        input.close();
        input.open("Key.txt");
        while (getline(input, line))
        {
            key += line + '\n';
        }
        text = decrypt(str, key);
        output << text;
        cout << "Cipher Text: " << endl;
        cout << str;
        cout << endl;
        cout << "Plain Text: " << endl;
        cout << text;
        cout << endl;
        break;

    default:
        cout << "Invalid choice." << endl;
        break;
    }

    cout << endl;

    return 0;
}
