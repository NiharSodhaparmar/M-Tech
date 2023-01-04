#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void merge(vector<int> &arr, int start, int end, int mid, long long int *count)
{
    int length1 = mid - start + 1;
    int length2 = end - mid;

    int *firstArray = new int[length1];
    int *secondArray = new int[length2];

    for (int i = 0; i < length1; i++)
    {
        firstArray[i] = arr[start + i];
    }

    for (int j = 0; j < length2; j++)
    {
        secondArray[j] = arr[mid + j + 1];
    }

    int mainArrayIndex = start;
    int index1 = 0;
    int index2 = 0;

    while (index1 < length1 && index2 < length2)
    {
        if (firstArray[index1] < secondArray[index2])
        {
            arr[mainArrayIndex++] = firstArray[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = secondArray[index2++];
        }
        *count = *count + 1;
    }

    while (index1 < length1)
    {
        arr[mainArrayIndex++] = firstArray[index1++];
        *count = *count + 1;
    }

    while (index2 < length2)
    {
        arr[mainArrayIndex++] = secondArray[index2++];
        *count = *count + 1;
    }

    delete[] firstArray;
    delete[] secondArray;
}

void mergeSort(vector<int> &arr, int start, int end, long long int *count)
{
    if (start >= end)
    {
        return;
    }

    int mid = start + (end - start) / 2;

    mergeSort(arr, start, mid, count);
    mergeSort(arr, mid + 1, end, count);

    merge(arr, start, end, mid, count);
}

int main()
{
    vector<int> arr;
    long long int count = 0;

    ifstream input("../SortedDataset10power5.txt");
    string line;

    while (getline(input, line))
    {
        arr.push_back(stoi(line));
    }

    cout << "Dataset size: " << arr.size() << endl;

    auto start = high_resolution_clock::now();

    // Calling Merge Sort
    mergeSort(arr, 0, arr.size() - 1, &count);

    auto end = high_resolution_clock::now();

    cout << "Number of swap required for Mergesort: " << count << endl;

    cout << "Time taken" << endl;
    cout << "\tNo of seconds: " << duration<double>(end - start).count() << endl;
    cout << "\tNo of micro seconds: " << duration_cast<microseconds>(end - start).count() << endl;

    return 0;
}