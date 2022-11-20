#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

vector<int> getMinGasStation(int tankCap, int totalDist, int gasStations[], int n);

int main()
{
    int tankCap = 100;
    int totalDist = 2000;
    int gasStations[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000};
    int n = sizeof(gasStations) / sizeof(gasStations[0]);

    cout << "Tank capacity: " << tankCap << " kms" << endl;
    cout << "Total distance: " << totalDist << " kms" << endl;
    cout << "Gas Stations: ";
    for (int i = 0; i < n - 1; i++)
    {
        cout << gasStations[i] << " ";
    }
    cout << endl;

    auto start = high_resolution_clock::now();
    vector<int> ans = getMinGasStation(tankCap, totalDist, gasStations, n);
    auto end = high_resolution_clock::now();

    cout << endl;
    if (ans.size())
    {
        cout << "No of statios that have to stop: " << ans.size() << endl;
        cout << "Gas stations where to stop: ";
        for (int i = 0; i < ans.size(); i++)
        {
            cout << gasStations[ans[i]] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Not Possible" << endl;
    }
    cout << "Time taken: " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds" << endl;

    return 0;
}

vector<int> getMinGasStation(int tankCap, int totalDist, int gasStations[], int n)
{
    int fuelRemaining = tankCap;
    vector<int> ans;
    if ((totalDist - gasStations[n - 1] > tankCap) || (gasStations[1] - gasStations[0] > tankCap))
        return ans;

    for (int i = 1; i < n - 1; i++)
    {
        fuelRemaining = fuelRemaining - (gasStations[i] - gasStations[i - 1]);

        if (gasStations[i + 1] - gasStations[i] > tankCap)
        {
            vector<int> tmp;
            return tmp;
        }
        else if (gasStations[i + 1] - gasStations[i] > fuelRemaining)
        {
            ans.push_back(i);
            fuelRemaining = tankCap;
        }
    }

    return ans;
}