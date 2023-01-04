#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void quickSort(vector<int> &arr, int low, int high);
int medianOfThree(vector<int> &arr, int low, int high);
int partition(vector<int> &arr, int low, int high, int pivot);
void manualSort(vector<int> &arr, int low, int high);
void check(vector<int> a);

int main()
{
    srand(time(NULL));
    vector<int> arr;
    int size = 1024;
    int numberOfTimes = 10;

    cout << "Dataset size: " << size << endl;
    cout << endl;

    for (int i = 0; i < numberOfTimes; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arr.push_back(rand());
        }

        auto start = high_resolution_clock::now();
        quickSort(arr, 0, arr.size() - 1);
        auto end = high_resolution_clock::now();

        cout << "Time taken for pass " << i << " : " << duration_cast<microseconds>(end - start).count() << " microseconds" << endl;

        check(arr);
        cout << endl;
    }
}

void quickSort(vector<int> &arr, int low, int high)
{
    int size = high - low + 1;
    if (size <= 3)
    {
        manualSort(arr, low, high);
    }
    else
    {
        int median = medianOfThree(arr, low, high);
        int pi = partition(arr, low, high, median);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int medianOfThree(vector<int> &arr, int low, int high)
{
    int center = (low + high) / 2;

    if (arr[low] > arr[center])
        swap(arr[low], arr[center]);

    if (arr[low] > arr[high])
        swap(arr[low], arr[high]);

    if (arr[center] > arr[high])
        swap(arr[center], arr[high]);

    swap(arr[center], arr[high - 1]);

    return arr[high - 1];
}

int partition(vector<int> &arr, int low, int high, int pivot)
{
    int left = low;
    int right = high - 1;

    while (true)
    {
        while (arr[++left] < pivot)
            ;
        while (arr[--right] > pivot)

            ;
        if (left >= right)
            break;
        else
            swap(arr[left], arr[right]);
    }
    swap(arr[left], arr[high - 1]);
    return left;
}

void manualSort(vector<int> &arr, int low, int high)
{
    int size = high - low + 1;
    if (size <= 1)
        return;
    if (size == 2)
    {
        if (arr[low] > arr[high])
            swap(arr[low], arr[high]);
        return;
    }
    else
    {
        if (arr[low] > arr[high - 1])
            swap(arr[low], arr[high - 1]);
        if (arr[low] > arr[high])
            swap(arr[low], arr[high]);
        if (arr[high - 1] > arr[high])
            swap(arr[high - 1], arr[high]);
    }
}

void check(vector<int> a)
{
    for (int i = 0; i < a.size() - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            cout << "Failed to sort. \tSee item " << i << endl
                 << endl;
            return;
        }
    }
    cout << "Check passed. Array is sorted." << endl;
}