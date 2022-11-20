#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int> changeMakingApproach1(int n, vector<int> D)
{
    vector<int> F(n + 1);
    F[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int temp = INT_MAX;
        int j = 0;
        while (j < D.size() && D[j] <= i)
        {
            temp = min(temp, F[i - D[j]] + 1);
            j++;
        }
        F[i] = temp;
    }

    return F;
}

vector<vector<int>> changeMakingApproach2(int n, vector<int> D)
{
    vector<vector<int>> C(D.size() + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= D.size(); i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 && j < D[i])
                C[i][j] = INT_MAX;
            else if (i == 1)
                C[i][j] = C[1][j - D[i]] + 1;
            else if (j < D[i])
                C[i][j] = C[i - 1][j];
            else
                C[i][j] = min(C[i - 1][j], C[i][j - D[i]] + 1);
        }
    }

    return C;
}

int main()
{
    vector<int> D = {1, 4, 5, 6};
    int n = 10;
    vector<int> F;

    F = changeMakingApproach1(n, D);
    cout << "Change Making using Approach 1: " << endl;
    for (int i = 0; i <= n; i++)
    {
        cout << i << "\t";
    }
    cout << endl;
    for (int i = 0; i <= n; i++)
    {
        cout << F[i] << "\t";
    }

    vector<vector<int>> C;
    vector<int> D1 = {0, 1, 4, 5, 6};
    C = changeMakingApproach2(n, D1);

    cout << endl;
    cout << endl;
    cout << "Change Making using Approach 2: " << endl;
    for (int i = 0; i <= D.size(); i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}