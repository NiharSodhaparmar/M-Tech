#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

void check(vector<int> a);
void countingSort(vector<int> &arr, int n);

int main()
{
    srand(time(NULL));

    vector<int> arr;

    int low = 0;
    int high = 99;

    for (int i = 0; i < 100000; i++)
    {
        arr.push_back(rand() % 100);
    }

    cout << "Dataset size: " << arr.size() << endl;

    auto start = high_resolution_clock::now();
    countingSort(arr, arr.size());
    auto end = high_resolution_clock::now();

    check(arr);

    cout << "Time taken" << endl;
    cout << "\tNo of micro seconds: " << duration_cast<microseconds>(end - start).count() << endl;
}

void countingSort(vector<int> &arr, int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    vector<int> count(max);
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        ++count[arr[i]];
    }

    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        ans[--count[arr[i]]] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = ans[i];
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