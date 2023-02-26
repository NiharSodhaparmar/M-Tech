#include <iostream>
#include <vector>
using namespace std;

/*
1, 2, 2, 2, 3, 4
2, 2, 3, 3
ans 2 2 3

3, 2
1, 2, 3
ans 3
*/

// https://www.codingninjas.com/codestudio/problems/intersection-of-2-arrays_1082149

vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    int i = 0;
    int j = 0;
    vector<int> ans;

    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    return ans;
}

int main()
{
    vector<int> arr1 = {3, 2};
    vector<int> arr2 = {1, 2, 3};

    vector<int> ans = findArrayIntersection(arr1, arr1.size(), arr2, arr2.size());
    cout << "Intersection array length: " << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}