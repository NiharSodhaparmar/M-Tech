#include <iostream>
using namespace std;

/*
You have been given an integer array of size N where N is equal to 2M + 1.
M numbers are present twice and one number is present only once.
*/

// https://www.codingninjas.com/codestudio/problems/find-unique_625159

int findUnique(int *arr, int size)
{
    int ans = 0;

    for (int i = 0; i < size; i++)
    {
        ans = ans ^ arr[i];
    }

    return ans;
}

int main()
{
    int a[] = {2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 11};
    int size = sizeof(a) / sizeof(a[0]);
    cout << "Unique number from array: " << findUnique(a, size) << endl;
}