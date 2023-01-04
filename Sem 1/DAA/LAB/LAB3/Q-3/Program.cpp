#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

int getMaxRevenue(int m, vector<int> x, vector<int> rev, int n, int t = 5);
int max(int a, int b);

int main()
{
    vector<int> m = {100, 1000, 10000, 100000};

    for (int k = 0; k < m.size(); k++)
    {
        vector<int> x;
        vector<int> r;
        int t = 2;

        srand(time(0));
        int a;
        for (int i = 5; i < m[k]; i = i + (rand() % 10) + 1)
        {
            x.push_back(i);
            a = (rand() % 10) + 1;
            r.push_back(a);
        }

        int n = x.size();
        auto start = high_resolution_clock::now();
        int maxRevenue = getMaxRevenue(m[k], x, r, n, t);
        auto end = high_resolution_clock::now();

        cout << "Max revenue for m = " << m[k] << " and t = " << t << ": " << maxRevenue << endl;
        cout << "Time taken: " << duration_cast<microseconds>(end - start).count() << " microseconds" << endl
             << endl;
    }
}

int getMaxRevenue(int m, vector<int> x, vector<int> r, int n, int t)
{
    vector<int> maxRev(m + 1);

    for (int i = 0; i < (m + 1); i++)
    {
        maxRev[i] = 0;
    }

    int nxtbb = 0;
    for (int i = 1; i <= m; i++)
    {
        if (nxtbb < n)
        {
            if (x[nxtbb] != i)
                maxRev[i] = maxRev[i - 1];

            else
            {
                if (i <= t)
                    maxRev[i] = max(maxRev[i - 1], r[nxtbb]);

                else
                    maxRev[i] = max(maxRev[i - t - 1] + r[nxtbb], maxRev[i - 1]);

                nxtbb++;
            }
        }
        else
            maxRev[i] = maxRev[i - 1];
    }

    return maxRev[m];
}

int max(int a, int b)
{
    return (a > b ? a : b);
}