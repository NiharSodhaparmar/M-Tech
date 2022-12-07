#include <iostream>
#include <math.h>
using namespace std;

int DPKnapsackWithMemoization(int W, int w[], int p[], int i, int **V)
{
    if (i < 0)
        return 0;

    if (V[i][W] != -1)
        return V[i][W];

    if (w[i] > W)
    {
        V[i][W] = DPKnapsackWithMemoization(W, w, p, i - 1, V);
    }
    else
    {
        V[i][W] = max(DPKnapsackWithMemoization(W, w, p, i - 1, V),
                      p[i] + DPKnapsackWithMemoization(W - w[i], w, p, i - 1, V));
    }

    return V[i][W];
}

int DPKnapsack(int W, int w[], int p[], int n)
{
    int **V = new int *[n];

    for (int i = 0; i < n; i++)
    {
        V[i] = new int[(W + 1)];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            V[i][j] = -1;
        }
    }

    int maxProfit = DPKnapsackWithMemoization(W, w, p, n - 1, V);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            cout << V[i][j] << '\t';
        }
        cout << endl;
    }
    cout << endl;

    return maxProfit;
}

int main()
{
    int W = 5;
    int w[] = {0, 2, 1, 3, 2};
    int p[] = {0, 12, 10, 20, 15};
    int n = sizeof(w) / sizeof(w[0]);

    int maxProfit = DPKnapsack(W, w, p, n);

    cout << "Maximum profit is: " << maxProfit << endl;

    return 0;
}