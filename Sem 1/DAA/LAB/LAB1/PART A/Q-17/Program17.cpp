#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

pair<int, int> getMinDistance(vector<long long int> &nums, long long int n)
{
    long long int min = INT_MAX;
    int index = -1;
    for (long long int i = 0; i < n - 1; i++)
    {
        if ((nums[i + 1] - nums[i]) < min)
        {
            min = (nums[i + 1] - nums[i]);
            index = i;
        }
    }
    return make_pair(index, min);
}

int main()
{
    vector<long long int> nums;
    ifstream input("../SortedDataset10Power6.txt");
    string line;

    while (getline(input, line))
    {
        nums.push_back(stoi(line));
    }

    cout << "Dataset size: " << nums.size() << endl;

    auto start = high_resolution_clock::now();

    pair<int, int> min = getMinDistance(nums, nums.size());

    auto end = high_resolution_clock::now();

    cout << "x = " << nums[min.first] << endl;
    cout << "y = " << nums[min.first + 1] << endl;
    cout << "|x - y|: " << min.second << endl;

    cout << "Time taken" << endl;
    cout << "\tNo of seconds: " << duration<double>(end - start).count() << endl;
    cout << "\tNo of micro seconds: " << duration_cast<microseconds>(end - start).count() << endl;
}