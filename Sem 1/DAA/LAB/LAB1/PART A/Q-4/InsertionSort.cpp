#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

unsigned long long int insertionSort(vector<int> &arr)
{
    int n = arr.size();
    int numberOfSwap = 0;
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
                numberOfSwap++;
            }
            else
            {
                break;
            }
            j--;
        }
        arr[j + 1] = temp;
    }

    return numberOfSwap;
}

int main()
{

    vector<int> nums;

    ifstream input("../Dataset10power5.txt");
    string line;

    while (getline(input, line))
    {
        nums.push_back(stoi(line));
    }

    cout << "Dataset size: " << nums.size() << endl;

    auto start = high_resolution_clock::now();

    // Calling Insertion Sort
    unsigned long long int numberOfSwap = insertionSort(nums);

    auto end = high_resolution_clock::now();

    cout << "Number of swap required for insertion sort : " << numberOfSwap << endl;

    cout << "Time taken" << endl;
    cout << "\tNo of seconds: " << duration<double>(end - start).count() << endl;
    cout << "\tNo of micro seconds: " << duration_cast<microseconds>(end - start).count() << endl;

    return 0;
}