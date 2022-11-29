#include <iostream>
#include <vector>
using namespace std;

void mergeSort(vector<int> &arr, int start, int end);
void merge(vector<int> &arr, int start, int mid, int end);

int main()
{
    vector<int> arr = {5, 4, 8, 9, 1, 3, 7, 6};
    int start = 0;
    int end = arr.size();

    mergeSort(arr, start, end - 1);

    for (int i = 0; i < end; i++)
    {
        cout << arr[i] << " ";
    }
}

void merge(vector<int> &arr, int start, int mid, int end)
{
    int length1 = mid - start + 1;
    int length2 = end - mid;

    vector<int> firstArray(length1);
    vector<int> secondArray(length2);

    for (int i = 0; i < length1; i++)
    {
        firstArray[i] = arr[start + i];
    }

    for (int i = 0; i < length2; i++)
    {
        secondArray[i] = arr[mid + i + 1];
    }

    int index1 = 0;
    int index2 = 0;
    int mainIndex = start;

    while (index1 < length1 && index2 < length2)
    {
        if (firstArray[index1] < secondArray[index2])
        {
            arr[mainIndex++] = firstArray[index1++];
        }
        else
        {
            arr[mainIndex++] = secondArray[index2++];
        }
    }

    while (index1 < length1)
    {
        arr[mainIndex++] = firstArray[index1++];
    }

    while (index2 < length2)
    {
        arr[mainIndex++] = secondArray[index2++];
    }
}

void mergeSort(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return;

    int mid = start + (end - start) / 2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    merge(arr, start, mid, end);
}