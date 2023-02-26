#include <iostream>
#include <vector>
using namespace std;

/* Given an array, rotate the array to the right by k steps, where k is non-negative.

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
*/

// https://leetcode.com/problems/rotate-array/

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> temp(n);

        for (int i = 0; i < n; i++)
        {
            temp[(i + k) % n] = nums[i];
        }
        nums = temp;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    cout << "Rotated array: " << endl;

    Solution sol = Solution();
    sol.rotate(nums, 3);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}