#include <vector>
#include <iostream>
#include <iostream>
using namespace std;

// Program 4
int partitionUsingPivotAsEnd_4(vector<int> &arr, int low, int high);
int partitionUsingPivotAsStart_4(vector<int> &arr, int low, int high);
void quickSortPivotAsStart_4(vector<int> &arr, int low, int high);
void quickSortPivotAsEnd_4(vector<int> &arr, int low, int high);

// Program 5
void quickSort_5(vector<int> &arr, int low, int high);
int medianOfThree_5(vector<int> &arr, int low, int high);
int partition_5(vector<int> &arr, int low, int high, int pivot);
void manualSort_5(vector<int> &arr, int low, int high);

// Program 6
int partition_6(vector<int> &arr, int low, int high);
int partition_r_6(vector<int> &arr, int low, int high);
void quickSort_6(vector<int> &arr, int low, int high);

int partitionUsingPivotAsStart_4(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int left = low + 1;
    int right = high;

    while (left < right)
    {
        while (arr[left] <= pivot)
            left++;

        while (arr[right] > pivot)
            right--;

        if (left < right)
        {
            swap(arr[left], arr[right]);
        }
    }
    swap(arr[low], arr[right]);

    return right;
}

void quickSortPivotAsStart_4(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;

    int pi = partitionUsingPivotAsStart_4(arr, low, high);
    quickSortPivotAsStart_4(arr, low, pi - 1);
    quickSortPivotAsStart_4(arr, pi + 1, high);
}

int partitionUsingPivotAsEnd_4(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int left = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            left++;
            swap(arr[j], arr[left]);
        }
    }
    swap(arr[left + 1], arr[high]);
    return left + 1;
}

void quickSortPivotAsEnd_4(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;

    int pi = partitionUsingPivotAsEnd_4(arr, low, high);
    quickSortPivotAsEnd_4(arr, low, pi - 1);
    quickSortPivotAsEnd_4(arr, pi + 1, high);
}

void manualSort_5(vector<int> &arr, int low, int high)
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

int medianOfThree_5(vector<int> &arr, int low, int high)
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

int partition_5(vector<int> &arr, int low, int high, int pivot)
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

void quickSort_5(vector<int> &arr, int low, int high)
{
    int size = high - low + 1;
    if (size <= 3)
    {
        manualSort_5(arr, low, high);
    }
    else
    {
        int median = medianOfThree_5(arr, low, high);
        int pi = partition_5(arr, low, high, median);
        quickSort_5(arr, low, pi - 1);
        quickSort_5(arr, pi + 1, high);
    }
}

int partition_6(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int left = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            left++;
            swap(arr[j], arr[left]);
        }
    }
    swap(arr[left + 1], arr[high]);
    return left + 1;
}

int partition_r_6(vector<int> &arr, int low, int high)
{

    int random = low + rand() % (high - low);

    swap(arr[random], arr[high]);

    return partition_6(arr, low, high);
}

void quickSort_6(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;

    int pi = partition_r_6(arr, low, high);
    quickSort_6(arr, low, pi - 1);
    quickSort_6(arr, pi + 1, high);
}