#include <iostream>
#include <vector>
using namespace std;

/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Input: nums = [2,0,1]
Output: [0,1,2]
*/

// https://leetcode.com/problems/sort-colors/

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0;
        int m = 0;
        int r = n - 1;

        while (m <= r)
        {
            if (nums[m] == 2)
            {
                swap(nums[m], nums[r]);
                r--;
            }
            else if (nums[m] == 0)
            {
                swap(nums[l], nums[m]);
                l++;
                m++;
            }
            else if (nums[m] == 1)
            {
                m++;
            }
        }
    }
};

int main()
{
    vector<int> a = {2, 0, 1};
    Solution sol = Solution();
    sol.sortColors(a);
    cout << "Sorted array: " << endl;
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
}