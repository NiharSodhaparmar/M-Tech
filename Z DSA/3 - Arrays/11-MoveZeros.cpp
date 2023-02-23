#include <iostream>
#include <vector>
using namespace std;

/* Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.
*/

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int i = 0;
        int j = 0;

        while (i < nums.size())
        {
            if (nums[i] != 0)
            {
                swap(nums[i], nums[j]);
                j++;
            }
            i++;
        }
    }
};

int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};
    cout << "After Moved Zeros: " << endl;

    Solution sol = Solution();
    sol.moveZeroes(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}