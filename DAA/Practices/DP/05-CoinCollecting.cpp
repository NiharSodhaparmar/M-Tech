#include <iostream>
#include <vector>
using namespace std;

int main()
{
    const int m = 6;
    const int n = 7;
    int C[m][n] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0},
        {0, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 1, 0, 0, 1},
        {0, 1, 0, 0, 0, 1, 0},
    };

    int F[m][n] = {0};

    for (int j = 2; j < n; j++)
    {
        F[1][j] = F[1][j - 1] + C[1][j];
    }

    for (int i = 2; i < m; i++)
    {
        F[i][1] = F[i - 1][1] + C[i][1];
        for (int j = 2; j < n; j++)
        {
            F[i][j] = max(F[i - 1][j], F[i][j - 1]) + C[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << F[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}