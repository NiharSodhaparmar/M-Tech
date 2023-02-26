#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.


Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

[0,0,0,0]
*/

// https://leetcode.com/problems/3sum/

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        int targetSum = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++)
        {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
            {
                int left = i + 1;
                int right = n - 1;

                while (left < right)
                {
                    int sum = targetSum - nums[i];
                    cout << "i, left, right: " << i << " " << left << " " << right << endl;
                    cout << "i, left, right: " << nums[i] << " " << nums[left] << " " << nums[right] << endl;
                    if (nums[left] + nums[right] == sum)
                    {
                        ans.push_back(vector<int>{nums[i], nums[left], nums[right]});

                        while (left < right && nums[left] == nums[left + 1])
                        {
                            left++;
                        }
                        while (left < right && nums[right] == nums[right - 1])
                        {
                            right--;
                        }

                        left++;
                        right--;
                    }
                    else if (nums[left] + nums[right] < sum)
                    {
                        left++;
                    }
                    else
                    {
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> a = {-1, 0, 1, 2, -1, -4};
    Solution sol = Solution();
    vector<vector<int>> ans = sol.threeSum(a);
    cout << "Number of Triplets: " << ans.size() << endl;
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