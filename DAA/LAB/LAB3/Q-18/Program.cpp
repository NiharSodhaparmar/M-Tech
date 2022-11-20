#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

long long int minNumberOfMessage(vector<int> data, int n);

int main()
{
    vector<int> m = {10, 100, 1000, 10000};

    for (int k = 0; k < m.size(); k++)
    {
        vector<int> data;

        for (int i = 0; i < m[k]; i++)
            data.push_back(1);

        int n = m[k];

        auto start = high_resolution_clock::now();
        long long int ans = minNumberOfMessage(data, n);
        auto end = high_resolution_clock::now();

        cout << "Ans : " << ans << endl;

        cout << "Time taken for " << n << " people : " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds" << endl
             << endl;
    }
}

long long int minNumberOfMessage(vector<int> data, int n)
{
    long long int count = 0;

    for (int i = 0; i < n - 1; i++)
    {
        data[i + 1] = data[i + 1] + data[i];
        count++;
    }

    for (int i = n - 1; i > 0; i--)
    {
        data[i - 1] = data[n - 1];
        count++;
    }

    return count;
}