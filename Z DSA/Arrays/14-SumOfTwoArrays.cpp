#include <iostream>
#include <vector>
using namespace std;

/*
You are given two numbers 'A' and 'B' in the form of two arrays (A[] and B[]) of lengths 'N' and 'M'
respectively, where each array element represents a digit. You need to find the sum of these two
numbers and return this sum in the form of an array.

A = 1, 2, 3, 4
B = 6
Ans = 1 2 4 0

A = 1 2 3
B = 9 9
Ans = 2 2 2
*/

void reverseArray(vector<int> &arr)
{
    int i = 0;
    int j = arr.size() - 1;

    while (i < j)
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

vector<int> findArraySum(vector<int> &a, int n, vector<int> &b, int m)
{
    int i = n - 1;
    int j = m - 1;
    vector<int> ans;
    int carry = 0;

    while (i >= 0 && j >= 0)
    {
        int sum = a[i] + b[j] + carry;
        carry = sum / 10;
        ans.push_back(sum % 10);
        i--;
        j--;
    }

    while (i >= 0)
    {
        int sum = a[i] + carry;
        carry = sum / 10;
        ans.push_back(sum % 10);
        i--;
    }

    while (j >= 0)
    {
        int sum = b[j] + carry;
        carry = sum / 10;
        ans.push_back(sum % 10);
        j--;
    }

    while (carry != 0)
    {
        int sum = carry;
        carry = sum / 10;
        ans.push_back(sum % 10);
    }

    reverseArray(ans);

    return ans;
}

int main()
{
    vector<int> a = {1, 2, 3, 4};
    vector<int> b = {6};

    vector<int> ans = findArraySum(a, a.size(), b, b.size());

    cout << "Sum of two digits: " << endl;

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
    }
}