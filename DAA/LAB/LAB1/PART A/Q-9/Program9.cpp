#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void bubbleSort(int a[]);
void insertSort(int a[]);
void mergeSort(int arr[], int p, int r);
void mySort(int arr[], int p, int r);
void semiBubbleSort(int a[]);
void fillRandom(int a[]);
void check(int a[]);

int N = 0;

int main(int argc, char *argv[])
{
    int a[10000];
    timeval t;

    N = atoi(argv[1]);

    // Time a bubble sort
    fillRandom(a);
    auto start = high_resolution_clock::now();
    bubbleSort(a);
    auto end = high_resolution_clock::now();
    cout << "Bubble Sort time : " << duration<double>(end - start).count() << " seconds" << endl;
    check(a);

    // Time a insertion sort
    fillRandom(a);
    start = high_resolution_clock::now();
    insertSort(a);
    end = high_resolution_clock::now();
    cout << "Insertion Sort time : " << duration<double>(end - start).count() << " seconds" << endl;
    check(a);

    // Time a merge sort
    fillRandom(a);
    start = high_resolution_clock::now();
    mergeSort(a, 0, N - 1);
    end = high_resolution_clock::now();
    cout << "Merge Sort time : " << duration<double>(end - start).count() << " seconds" << endl;
    check(a);

    // Time a improved merge sort
    fillRandom(a);
    start = high_resolution_clock::now();
    mySort(a, 0, N - 1);
    end = high_resolution_clock::now();
    cout << "Improved Merge Sort time : " << duration<double>(end - start).count() << " seconds" << endl;
    check(a);

    // Time a semi bubble sort
    fillRandom(a);
    start = high_resolution_clock::now();
    semiBubbleSort(a);
    end = high_resolution_clock::now();
    cout << "Semi Bubble Sort time : " << duration<double>(end - start).count() << " seconds" << endl;
    check(a);

    return 0;
}

// Bubble Sort
void bubbleSort(int a[])
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

// Insertion Sort
void insertSort(int a[])
{
    int i, j, temp;
    for (int i = 1; i < N; i++)
    {
        int temp = a[i];
        int j = i - 1;
        while (j >= 0)
        {
            if (a[j] > temp)
            {
                a[j + 1] = a[j];
            }
            else
            {
                break;
            }
            j--;
        }
        a[j + 1] = temp;
    }
}

// Merge
void merge(int arr[], int start, int end, int mid)
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
}

// Merge Sort
void mergeSort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int mid = start + (end - start) / 2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    merge(arr, start, end, mid);
}

// Improved Merge
void mergeImproved(int a[], int start, int end, int mid)
{
    int length1 = mid - start + 1;
    int length2 = end - mid;

    int *firstArray = new int[length1];
    int *secondArray = new int[length2];

    for (int i = 0; i < length1; i++)
    {
        firstArray[i] = a[start + i];
    }

    for (int j = 0; j < length2; j++)
    {
        secondArray[j] = a[mid + j + 1];
    }

    int mainArrayIndex = start;

    if (firstArray[length1 - 1] < secondArray[0])
    {
    }
    else if (firstArray[0] > secondArray[length2 - 1])
    {

        for (int j = 0; j < length2; j++)
        {
            a[mainArrayIndex++] = secondArray[j];
        }

        for (int i = 0; i < length1; i++)
        {
            a[mainArrayIndex++] = firstArray[i];
        }
    }
    else
    {

        int index1 = 0;
        int index2 = 0;

        while (index1 < length1 && index2 < length2)
        {
            if (firstArray[index1] < secondArray[index2])
            {
                a[mainArrayIndex++] = firstArray[index1++];
            }
            else
            {
                a[mainArrayIndex++] = secondArray[index2++];
            }
        }

        while (index1 < length1)
        {
            a[mainArrayIndex++] = firstArray[index1++];
        }

        while (index2 < length2)
        {
            a[mainArrayIndex++] = secondArray[index2++];
        }
    }

    delete[] firstArray;
    delete[] secondArray;
}

// Improved Merge Sort
void mySort(int a[], int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int mid = start + (end - start) / 2;

    mySort(a, start, mid);
    mySort(a, mid + 1, end);

    mergeImproved(a, start, end, mid);
}

// Semi Bubble Sort
void semiBubbleSort(int a[])
{
    bool swapped = true;
    int start = 0;
    int end = N - 1;
    while (swapped)
    {
        swapped = false;
        for (int i = start; i < end; ++i)
        {
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
        swapped = false;
        --end;
        for (int i = end - 1; i >= start; --i)
        {
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        ++start;
    }
}

// Fill Random Data
void fillRandom(int a[])
{
    for (int i = 0; i < N; i++)
    {
        a[i] = rand();
    }
}

// Check array is sorted or not
void check(int a[])
{
    for (int i = 0; i < N - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            cout << "Failed to sort. \tSee item " << i << endl
                 << endl;
            return;
        }
    }
    cout << "Check passed" << endl
         << endl;
}
