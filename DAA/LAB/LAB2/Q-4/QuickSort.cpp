#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int partitionUsingPivotAsEnd(vector<int> &arr, int low, int high, long long int *count);
int partitionUsingPivotAsStart(vector<int> &arr, int low, int high, long long int *count);
void quickSortPivotAsStart(vector<int> &arr, int low, int high, long long int *count);
void quickSortPivotAsEnd(vector<int> &arr, int low, int high, long long int *count);

int main()
{
    vector<int> arr1;
    vector<int> arr2;
    long long int count1 = 0, count2 = 0;

    ifstream input("../Dataset10power6.txt");
    string line;

    while (getline(input, line))
    {
        arr1.push_back(stoi(line));
        arr2.push_back(stoi(line));
    }

    cout << "Dataset size: " << arr1.size() << endl;

    auto start = high_resolution_clock::now();
    // Calling Quick Sort Pivot As Start
    quickSortPivotAsStart(arr1, 0, arr1.size() - 1, &count1);
    auto end = high_resolution_clock::now();

    cout << endl;
    cout << "Number of swap required for Quicksort Pivot As Start: " << count1 << endl;
    cout << "Time taken" << endl;
    cout << "\tNo of micro seconds: " << duration_cast<microseconds>(end - start).count() << endl;

    start = high_resolution_clock::now();
    // Calling Quick Sort Pivot As End
    quickSortPivotAsEnd(arr2, 0, arr2.size() - 1, &count2);
    end = high_resolution_clock::now();

    cout << endl;
    cout << "Number of swap required for Quicksort Pivot As End: " << count2 << endl;
    cout << "Time taken" << endl;
    cout << "\tNo of micro seconds: " << duration_cast<microseconds>(end - start).count() << endl;
}

int partitionUsingPivotAsStart(vector<int> &arr, int low, int high, long long int *count)
{
    int pivot = arr[low];
    int left = low + 1;
    int right = high;

    while (left < right)
    {
        while (arr[left] < pivot)
            left++;

        while (arr[right] > pivot)
            right--;

        if (left < right)
        {
            swap(arr[left], arr[right]);
            *count = *count + 1;
        }
    }
    swap(arr[low], arr[right]);
    *count = *count + 1;

    return right;
}

void quickSortPivotAsStart(vector<int> &arr, int low, int high, long long int *count)
{
    if (low >= high)
        return;

    int pi = partitionUsingPivotAsStart(arr, low, high, count);
    quickSortPivotAsStart(arr, low, pi - 1, count);
    quickSortPivotAsStart(arr, pi + 1, high, count);
}

int partitionUsingPivotAsEnd(vector<int> &arr, int low, int high, long long int *count)
{
    int pivot = arr[high];
    int left = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            left++;
            swap(arr[j], arr[left]);
            *count = *count + 1;
        }
    }
    swap(arr[left + 1], arr[high]);
    *count = *count + 1;
    return left + 1;
}

void quickSortPivotAsEnd(vector<int> &arr, int low, int high, long long int *count)
{
    if (low >= high)
        return;

    int pi = partitionUsingPivotAsEnd(arr, low, high, count);
    quickSortPivotAsEnd(arr, low, pi - 1, count);
    quickSortPivotAsEnd(arr, pi + 1, high, count);
}