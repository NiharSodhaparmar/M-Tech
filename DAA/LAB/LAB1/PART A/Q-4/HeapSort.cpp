#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void heapify(vector<int> &arr, int n, int i, long long int *count)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        *count = *count + 1;
        heapify(arr, n, largest, count);
    }
}

void heapSort(vector<int> &arr, int n, long long int *count)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i, count);
    }

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        *count = *count + 1;
        heapify(arr, i, 0, count);
    }
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

    // Calling Heap Sort
    heapSort(arr, arr.size(), &count);

    auto end = high_resolution_clock::now();

    cout << "Number of swap required for Heapsort: " << count << endl;

    cout << "Time taken" << endl;
    cout << "\tNo of seconds: " << duration<double>(end - start).count() << endl;
    cout << "\tNo of micro seconds: " << duration_cast<microseconds>(end - start).count() << endl;
}