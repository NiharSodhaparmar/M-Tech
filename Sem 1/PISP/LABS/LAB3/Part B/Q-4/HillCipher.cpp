#include <bits/stdc++.h>
using namespace std;

void get_key_matrix(string key, int key_matrix[][3])
{
    int k = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if ('A' <= key[k] && 'Z' >= key[k])
            {
                key_matrix[i][j] = (key[k]) % 65;
            }
            else
            {
                key_matrix[i][j] = (key[k]) % 97;
            }
            k++;
        }
    }
}

void getCofactor(int A[3][3], int temp[3][3], int p, int q, int n)
{
    int i = 0, j = 0;

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row != p && col != q)
            {
                temp[i][j++] = A[row][col];

                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

int determinant(int A[3][3], int n)
{
    int D = 0;
    int X = 0;
    if (n == 1)
        return A[0][0];

    int temp[3][3];
    int sign = 1;
    for (int f = 0; f < n; f++)
    {
        getCofactor(A, temp, 0, f, n);
        D += sign * A[0][f] * determinant(temp, n - 1);

        sign = -sign;
    }
    if (D > 0)
    {
        return D % 26;
    }
    else
    {
        int c = D % 26 + 26;
        return c > 25 ? 0 : c;
    }
}

void adjoint(int A[3][3], int adj[3][3])
{
    if (3 == 1)
    {
        adj[0][0] = 1;
        return;
    }
    int sign = 1, temp[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            getCofactor(A, temp, i, j, 3);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            int a = (sign) * (determinant(temp, 3 - 1));
            if (a > 0)
            {
                adj[j][i] = a;
            }
            else
            {
                adj[j][i] = a + 26;
            }
        }
    }
}

bool inverse(int A[3][3], int inverse[3][3])
{
    int det = determinant(A, 3);
    if (det == 0)
    {
        cout << "Singular matrix, can't find its inverse";
        return false;
    }
    int d_inverse[26] = {0, 1, 0, 9, 0, 21, 0, 15, 0, 3, 0, 19, 0, 0, 0, 7, 0, 23, 0, 11, 0, 5, 0, 17, 0, 25};
    int det_mod26;
    if (d_inverse[det] == 0)
    {
        cout << "Singular matrix, can't find its inverse";
        return false;
    }
    else
    {
        det_mod26 = d_inverse[det];
    }
    int adj[3][3];
    adjoint(A, adj);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            inverse[i][j] = (adj[i][j] * det_mod26) % 26;

    return true;
}

bool get_key_matrix_decrypt(string key, int key_matrix[][3])
{
    int matrix[3][3];
    get_key_matrix(key, matrix);
    return inverse(matrix, key_matrix);
}

string encrypt(int key_matrix[][3], string message_string)
{
    int x, i, j;
    string cipher_text = "";
    for (i = 0; i < 3; i++)
    {
        int multiply_val = 0;

        for (x = 0; x < 3; x++)
        {
            multiply_val += key_matrix[i][x] * message_string[x];
        }
        cipher_text += (multiply_val % 26) + 65;
    }
    return cipher_text;
}

string HillCipher_encrypt(string message, string key)
{
    int key_matrix[3][3];
    string message_string;
    string cipher_text;

    get_key_matrix(key, key_matrix);

    while (message.size() % 3 != 0)
    {
        message += "X";
    }

    for (int j = 0; j < message.size(); j += 3)
    {
        message_string = "";
        for (int i = 0; i < 3; i++)
        {
            if ('A' <= message[j + i] && 'Z' >= message[j + i])
            {
                message_string += (message[j + i]) % 65;
            }
            else
            {
                message_string += (message[j + i]) % 97;
            }
        }

        cipher_text += encrypt(key_matrix, message_string);
    }

    return cipher_text;
}

string HillCipher_decrypt(string message, string key)
{
    int key_matrix[3][3];
    string message_string;
    string plain_text = "";

    if (get_key_matrix_decrypt(key, key_matrix))
    {
        for (int j = 0; j < message.size(); j += 3)
        {
            message_string = "";
            for (int i = 0; i < 3; i++)
            {
                if ('A' <= message[j + i] && 'Z' >= message[j + i])
                {
                    message_string += (message[j + i]) % 65;
                }
                else
                {
                    message_string += (message[j + i]) % 97;
                }
            }

            plain_text += encrypt(key_matrix, message_string);
        }
    }
    else
    {
        cout << "\ndecryption is not possible for given key";
    }

    return plain_text;
}

int main()
{
    int a;

    ifstream input;
    ofstream output;

    string str, key;

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
        getline(input, str);
        input.close();
        input.open("Key.txt");
        getline(input, key);
        text = HillCipher_encrypt(str, key);
        output << text;
        cout << "Input Text: " << endl;
        cout << str << endl;
        cout << endl;
        cout << "Cipher Text: " << endl;
        cout << text << endl;
        break;

    case 2:
        input.open("CipherText.txt");
        output.open("PlainText.txt");
        getline(input, str);
        input.close();
        input.open("Key.txt");
        getline(input, key);
        text = HillCipher_decrypt(str, key);
        output << text;
        cout << "Cipher Text: " << endl;
        cout << str << endl;
        cout << endl;
        cout << "Plain Text: " << endl;
        cout << text << endl;
        break;

    default:
        cout << "Invalid choice." << endl;
        break;
    }

    cout << endl;

    return 0;
}