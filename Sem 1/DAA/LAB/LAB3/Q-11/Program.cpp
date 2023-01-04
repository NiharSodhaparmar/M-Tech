#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

bool selectColumn(const vector<int> &v1, const vector<int> &v2);
long long getMinCost(vector<vector<int>> &data);

int main()
{
    long long result = 0;
    vector<int> n = {10, 100, 1000, 10000, 100000};

    for (int k = 0; k < n.size(); k++)
    {
        int temp = 1;
        vector<vector<int>> data(n[k]);

        for (int i = 0; i < n[k]; i++)
        {
            data[i] = vector<int>(2);
            data[i][0] = i + 1;
            data[i][1] = temp++;
        }
        auto start = high_resolution_clock::now();
        result = getMinCost(data);
        auto end = high_resolution_clock::now();

        cout << "For n = " << data.size() << endl;
        cout << "\tTotal Cost = " << result << endl;
        cout << "\tTime Taken = " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds" << endl;
        data.clear();
    }

    return 0;
}

bool selectColumn(const vector<int> &v1, const vector<int> &v2)
{
    return v1[1] > v2[1];
}

long long getMinCost(vector<vector<int>> &data)
{
    long long count = 0;
    sort(data.begin(), data.end(), selectColumn);

    int month = 1;
    int temp = 0;
    for (int i = 0; i < data.size(); i++)
    {
        if (month == 1)
        {
            temp = 100;
        }
        temp = 100 * data[i][1] * month;
        count += temp;
        month++;
    }

    return count;
}