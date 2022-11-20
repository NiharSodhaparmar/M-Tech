#include <iostream>
#include <vector>
using namespace std;

/*
You are given array of size containing each number between 0 to N-1 at least once.
There is a single value  present in array is twice. Find duplicate in array.

4 2 1 3 1
6 3 1 5 4 3 2
8 7 2 5 4 7 1 3 6
*/

int findDuplicate(vector<int> &arr)
{
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        ans = ans ^ arr[i];
    }

    for (int i = 1; i < arr.size(); i++)
    {
        ans = ans ^ i;
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 4};
    cout << "Duplicate in array: " << findDuplicate(arr) << endl;
}