#include <iostream>
#include <math.h>
using namespace std;

int DPKnapsack(int w[], int p[], int n, int W)
{
    int **V = new int *[n];

    for (int i = 0; i < n; i++)
    {
        V[i] = new int[(W + 1)];
    }

    for (int i = 0; i <= n; i++)
    {
        V[i][0] = 0;
    }

    for (int j = 0; j <= W; j++)
    {
        V[0][j] = 0;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (j - w[i] >= 0)
            {
                V[i][j] = max((p[i] + V[i - 1][j - w[i]]), V[i - 1][j]);
            }
            else
            {
                V[i][j] = V[i - 1][j];
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j <= W; j++)
    //     {
    //         cout << V[i][j] << '\t';
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    int maxProfit = V[n - 1][W];

    for (int i = 0; i < n; i++)
    {
        delete[] V[i];
    }
    delete[] V;

    return maxProfit;
}

int main()
{
    int W = 11;
    int w[] = {0, 1, 2, 5, 6, 7};
    int p[] = {0, 1, 6, 18, 22, 28};
    int n = sizeof(w) / sizeof(w[0]);

    int maxProfit = DPKnapsack(w, p, n, W);

    cout << "Maximum profit is: " << maxProfit << endl;

    return 0;
}