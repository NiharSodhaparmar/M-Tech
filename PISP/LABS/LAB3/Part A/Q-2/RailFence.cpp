#include <iostream>
#include <vector>
using namespace std;

string encrypt(string s)
{
    vector<char> a, b;
    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (i % 2 == 0)
            a.push_back(s[i]);
        else
            b.push_back(s[i]);
    }

    for (int i = 0; i < a.size(); i++)
        ans += a[i];

    for (int i = 0; i < b.size(); i++)
        ans += b[i];

    return ans;
}

string decrypt(string s)
{
    string ans = "";
    int mid = s.length() / 2;

    for (int i = 0; i < mid; i++)
    {
        ans += s[i];
        ans += s[mid + i];
    }
    return ans;
}

int main()
{
    vector<char> a, b;
    string plaiText = "NIHARSODHAPARMAR";

    string cipherText = encrypt(plaiText);
    string decryptText = decrypt(cipherText);

    cout << endl;
    cout << "Plain Text : " << plaiText << endl;

    cout << endl;
    cout << "Cipher Text : " << cipherText << endl;

    cout << endl;
    cout << "Decrypted Text : " << decryptText << endl;

    return 0;
}