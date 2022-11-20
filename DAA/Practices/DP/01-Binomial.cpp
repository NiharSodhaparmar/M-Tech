#include <iostream>
using namespace std;

int main()
{
    const int n = 5;
    const int k = 2;
    int B[n + 1][k + 1] = {0};

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= min(i, k); j++)
        {
            if (j == 0 || i == j)
                B[i][j] = 1;
            else
                B[i][j] = B[i - 1][j - 1] + B[i - 1][j];
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            cout << B[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}