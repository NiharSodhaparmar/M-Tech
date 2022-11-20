#include <iostream>
#include <vector>
#include <chrono>
#include "myHeader.h"
using namespace std;
using namespace std::chrono;

int main()
{
    srand(time(NULL));
    vector<int> vect1;
    vector<int> tmp;
    int N = 100000;

    for (int j = 0; j < N; j++)
    {
        vect1.push_back(rand());
    }

    cout << endl
         << "Dataset Size : " << vect1.size() << endl;

    // Program 4 --> Start as Pivot
    for (int i = 0; i < N; i++)
        tmp.push_back(vect1[i]);

    auto start = high_resolution_clock::now();
    quickSortPivotAsStart_4(tmp, 0, tmp.size() - 1);
    auto end = high_resolution_clock::now();
    cout << "\tTime taken for start as pivot\t\t: " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds" << endl;

    // Program 4 --> End as Pivot
    for (int i = 0; i < N; i++)
        tmp.push_back(vect1[i]);

    start = high_resolution_clock::now();
    partitionUsingPivotAsEnd_4(tmp, 0, tmp.size() - 1);
    end = high_resolution_clock::now();
    cout << "\tTime taken for end as pivot\t\t: " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds" << endl;

    // Program 5 --> Median of three as Pivot
    for (int i = 0; i < N; i++)
        tmp.push_back(vect1[i]);

    start = high_resolution_clock::now();
    quickSort_5(tmp, 0, tmp.size() - 1);
    end = high_resolution_clock::now();
    cout << "\tTime taken for median of three as pivot : " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds" << endl;

    // Program 5 --> Random as Pivot
    for (int i = 0; i < N; i++)
        tmp.push_back(vect1[i]);

    start = high_resolution_clock::now();
    quickSort_6(tmp, 0, tmp.size() - 1);
    end = high_resolution_clock::now();
    cout << "\tTime taken for random as pivot\t\t: " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds" << endl;

    return 0;
}