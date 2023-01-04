#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

int partition(vector<int> &arr, int low, int high);
int partition_r(vector<int> &arr, int low, int high);
void quicksort(vector<int> &arr, int low, int high);
void check(vector<int> a);

int main()
{
    srand(time(NULL));

    vector<int> arr;
    int size = 1024;
    int numberOfTimes = 10;

    for (int i = 0; i < numberOfTimes; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arr.push_back(rand());
        }

        auto start = high_resolution_clock::now();
        quicksort(arr, 0, arr.size() - 1);
        auto end = high_resolution_clock::now();

        check(arr);

        cout << "Time taken no of micro seconds for pass " << i << ": " << duration_cast<microseconds>(end - start).count() << endl;
        cout << endl;
    }
}

int partition(vector<int> &arr, int low, int high)
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

int partition_r(vector<int> &arr, int low, int high)
{

    int random = low + rand() % (high - low);

    swap(arr[random], arr[high]);

    return partition(arr, low, high);
}

void quicksort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;

    int pi = partition_r(arr, low, high);
    quicksort(arr, low, pi - 1);
    quicksort(arr, pi + 1, high);
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
    cout << "Check passed" << endl;
}