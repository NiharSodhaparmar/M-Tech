#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int partitionUsingPivotAsEnd(vector<int> &arr, int start, int end, long long int *count)
{
    int pivot = arr[end];
    int i = start - 1;

    for (int j = start; j <= end; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[j], arr[i]);
            *count = *count + 1;
        }
    }
    swap(arr[i + 1], arr[end]);
    *count = *count + 1;
    return i + 1;
}

int partitionUsingPivotAsStart(vector<int> &arr, int start, int end, long long int *count)
{
    int pivot = arr[start];
    int i = start;
    int j = end;

    while (i < j)
    {
        while (arr[i] <= pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i < j)
        {
            swap(arr[i], arr[j]);
            *count = *count + 1;
        }
    }
    swap(arr[start], arr[j]);
    *count = *count + 1;
    return j;
}

void quickSort(vector<int> &arr, int start, int end, long long int *count)
{
    if (start >= end)
        return;

    int pi = partitionUsingPivotAsEnd(arr, start, end, count);
    quickSort(arr, start, pi - 1, count);
    quickSort(arr, pi + 1, end, count);
}

int main()
{
    vector<int> arr;
    long long int count = 0;

    ifstream input("../Dataset10power6.txt");
    string line;

    while (getline(input, line))
    {
        arr.push_back(stoi(line));
    }

    cout << "Dataset size: " << arr.size() << endl;

    auto start = high_resolution_clock::now();

    // Calling Quick Sort
    quickSort(arr, 0, arr.size() - 1, &count);

    auto end = high_resolution_clock::now();

    cout << "Number of swap required for Quicksort: " << count << endl;

    cout << "Time taken" << endl;
    cout << "\tNo of seconds: " << duration<double>(end - start).count() << endl;
    cout << "\tNo of micro seconds: " << duration_cast<microseconds>(end - start).count() << endl;

    return 0;
}