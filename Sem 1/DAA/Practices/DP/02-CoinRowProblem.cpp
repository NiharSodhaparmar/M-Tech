#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    vector<int> cost = {0, 7, 2, 1, 12, 5};
    int n = cost.size();
    vector<int> F(n + 1);

    F[0] = 0;
    F[1] = cost[1];

    for (int i = 2; i < n; i++)
    {
        F[i] = max((cost[i] + F[i - 2]), F[i - 1]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << "\t";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << F[i] << "\t";
    }
}