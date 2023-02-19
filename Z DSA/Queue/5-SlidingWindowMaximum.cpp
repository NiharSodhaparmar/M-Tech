#include <iostream>
#include <vector>
#include <deque>
#include <limits.h>
using namespace std;

// https://leetcode.com/problems/sliding-window-maximum/
// Not passing for window 1

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ans;
        deque<int> dq;

        for (int i = 0; i < nums.size(); i++)
        {
            while (!dq.empty() && dq.front() < i - k + 1)
            {
                dq.pop_front();
            }

            while (!dq.empty() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }

            dq.push_back(i);

            if (i >= k - 1)
            {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;

    vector<int> nums = {1, 3, 1, 2, 0, 5};
    int k = 3;

    vector<int> ans = s.maxSlidingWindow(nums, k);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}