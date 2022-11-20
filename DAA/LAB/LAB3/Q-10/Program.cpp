#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

vector<int> baseStation(vector<int> house);

int main()
{
    vector<int> m = {10, 100, 1000, 10000, 100000, 1000000};

    srand(time(0));
    for (int k = 0; k < m.size(); k++)
    {
        vector<int> house;

        for (int i = 0; i < m[k]; i++)
        {
            house.push_back(rand() * (rand() % 60));
        }

        auto start = high_resolution_clock::now();
        vector<int> ans = baseStation(house);
        auto end = high_resolution_clock::now();

        cout << "For Total City : " << m[k] << endl;
        cout << "\tNumber of tower = " << ans.size() << endl;
        cout << "\tTime Tiken = " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds" << endl;
    }

    return 0;
}

vector<int> baseStation(vector<int> house)
{
    vector<int> ans;

    sort(house.begin(), house.end());

    int tower = house[0] + 4;
    ans.push_back(tower);

    int i = 1;

    while (i < house.size())
    {
        if ((tower + 4) >= house[i])
        {
            i++;
        }
        else
        {
            tower = house[i] + 4;
            ans.push_back(tower);
        }
    }

    return ans;
}