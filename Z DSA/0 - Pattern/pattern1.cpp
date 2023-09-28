#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i + 1; j++)
        {
            cout << " ";
        }

        cout << i + 1;

        if (i == 0)
        {
            cout << endl;
            continue;
        }

        for (int j = 0; j < 2 * i - 1; j++)
        {
            cout << " ";
        }

        cout << i + 1;
        cout << endl;
    }

    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < n - i + 2; j++)
        {
            cout << " ";
        }

        cout << i;

        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }

        cout << i;

        cout << endl;
    }
}
