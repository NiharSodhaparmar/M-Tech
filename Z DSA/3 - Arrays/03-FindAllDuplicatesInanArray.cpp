#include <iostream>
#include <vector>
using namespace std;

/*
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]

Input: nums = [1,1,2]
Output: [1]

Input: nums = [1]
Output: []
*/

// https://leetcode.com/problems/find-all-duplicates-in-an-array/

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0)
            {
                ans.push_back(index + 1);
            }
            else
            {
                nums[index] = -nums[index];
            }
        }

        return ans;
    }
};

int main()
{
    vector<int> a = {1, 2, 2};
    Solution sol = Solution();
    vector<int> ans = sol.findDuplicates(a);
    cout << "Duplicates in array: " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}