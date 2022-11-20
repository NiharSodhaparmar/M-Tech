#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;

long long int findInversionBruteForce(vector<int> arr, int n);
long long int mergeAndCount(vector<int> &arr, int start, int end, int mid);
long long int mergeSortAndCount(vector<int> &arr, int start, int end);

int main()
{
    vector<int> nums;

    ifstream input("../Dataset10power6.txt");
    string line;

    while (getline(input, line))
    {
        nums.push_back(stoi(line));
    }

    for (int i = 10; i <= 100000; i = i * 10)
    {
        cout << "Dataset size: " << i << endl;
        auto startBruteForce = high_resolution_clock::now();
        cout << "Inversion Count By Brute Force: " << findInversionBruteForce(nums, i) << endl;
        auto endBruteForce = high_resolution_clock::now();

        auto startMergeSort = high_resolution_clock::now();
        cout << "Inversion Count By Merge Sort: " << mergeSortAndCount(nums, 0, i - 1) << endl;
        auto endMergeSort = high_resolution_clock::now();

        cout << "Time taken by Brute Force: " << endl;
        cout << "\tNo of micro seconds: " << duration_cast<microseconds>(endBruteForce - startBruteForce).count() << endl;

        cout << "Time taken by Merge Sort: " << endl;
        cout << "\tNo of micro seconds: " << duration_cast<microseconds>(endMergeSort - startMergeSort).count() << endl;
        cout << endl;
    }
}

long long int findInversionBruteForce(vector<int> arr, int n)
{
    long long int inversionCount = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                inversionCount++;
        }
    }
    return inversionCount;
}

long long int mergeAndCount(vector<int> &arr, int start, int end, int mid)
{
    long long int inversionCount = 0;
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
            inversionCount += (length1 - index1);
        }
    }

    while (index1 < length1)
    {
        arr[mainArrayIndex++] = firstArray[index1++];
    }

    while (index2 < length2)
    {
        arr[mainArrayIndex++] = secondArray[index2++];
    }

    delete[] firstArray;
    delete[] secondArray;

    return inversionCount;
}

long long int mergeSortAndCount(vector<int> &arr, int start, int end)
{
    long long int inversionCount = 0;
    if (start >= end)
    {
        return inversionCount;
    }

    int mid = start + (end - start) / 2;

    inversionCount += mergeSortAndCount(arr, start, mid);
    inversionCount += mergeSortAndCount(arr, mid + 1, end);
    inversionCount += mergeAndCount(arr, start, end, mid);

    return inversionCount;
}