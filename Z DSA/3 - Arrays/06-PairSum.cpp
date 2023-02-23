#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <math.h>
using namespace std;

/*
1, 2, 3, 4, 5
s = 5
output
1 4
2 3

2, -3, 3, 3, -2
s = 0
output
-3 3
-3 3
-2 2

2, -6, 2, 5, 2
s = 4
output

*/

vector<vector<int>> pairSum1(vector<int> &arr, int s)
{
    vector<vector<int>> ans;
    unordered_map<int, int> mp;

    for (int i = 0; i < arr.size(); i++)
    {
        int secondNumber = s - arr[i];

        if (mp.find(secondNumber) != mp.end())
        {
            ans.push_back(vector<int>{min(arr[i], secondNumber), max(arr[i], secondNumber)});
        }

        mp[arr[i]] = i;
    }

    sort(ans.begin(), ans.end());

    return ans;
}

vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    vector<vector<int>> ans;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (s == arr[i] + arr[j])
                ans.push_back(vector<int>{min(arr[i], arr[j]), max(arr[i], arr[j])});
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
}

// LeetCode
vector<int> pairSumLeetCode(vector<int> &nums, int target)
{
    vector<int> ans;
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++)
    {
        int secondNumber = target - nums[i];

        if (mp.find(secondNumber) != mp.end())
        {
            ans.push_back(i);
            ans.push_back(mp[secondNumber]);
            return ans;
        }

        mp[nums[i]] = i;
    }

    return ans;
}

int main()
{
    vector<int> arr = {2, -6, 2, 5, 2};
    int s = 4;
    vector<vector<int>> ans = pairSum1(arr, s);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "Pair " << i << ": ";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}