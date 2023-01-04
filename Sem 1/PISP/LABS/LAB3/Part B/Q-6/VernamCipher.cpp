#include <bits/stdc++.h>
using namespace std;

string encrypt(string input, string key)
{
    int j = 0;
    string output;
    for (int i = 0; i < input.length(); i++)
    {
        output += input[i] ^ key[j];

        j = (j + 1) % key.length();
    }

    return output;
}

int main()
{
    string line, input, output, key;
    ifstream file("Input.txt");
    ifstream inputKey("Key.txt");

    while (getline(file, line))
    {
        input += (line);
    }

    getline(inputKey, key);

    cout << endl;
    cout << "Input text: " << endl;
    cout << input << endl;
    cout << endl;

    string cipher = encrypt(input, key);
    cout << "Cipher Text: " << endl;
    cout << cipher << endl;
    cout << endl;

    string plain = encrypt(cipher, key);
    cout << "Plain Text: " << endl;
    cout << plain << endl;
    cout << endl;

    return 0;
}