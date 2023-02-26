#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> a = {{1, 3, 7}, {2, 5, 4}, {4, 8, 6}};
    vector<vector<int>> b = {{3, 5}, {5, 8}};

    int n = a.size();
    int q = b.size();
    int count = 0;

    map<int, vector<int>> line;

    for (int i = 0; i < n; i++)
    {
        for (int j = a[i][0]; j <= a[i][1]; j++)
        {
            line[j].push_back(a[i][2]);
            count++;
        }
    }

    // for (auto k : line)
    // {
    //     int size = k.second.size();
    //     for (int i = 0; i < size; i++)
    //     {
    //         cout << k.second[i] << " ";
    //     }
    //     cout << endl;
    // }

    // cout << count;

    // cout << line[b[0][0]].size();

    for (int i = 0; i < q; i++)
    {
        vector<int> temp = line[b[i][0]];
        for (int k = 0; k < temp.size(); k++)
        {
            // cout << "temp " << temp[k] << " ";
            if (temp[k] <= b[i][1])
            {
                count--;
            }
        }
        cout << count << endl;
    }
}