#include <iostream>
#include <vector>
using namespace std;

// Need to check output is complete

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (j >= 0)
        {
            if (i >= 0 && nums1[i] > nums2[j])
            {
                nums1[k--] = nums1[i--];
            }
            else
            {
                nums1[k--] = nums2[j--];
            }
        }
    }
};

int main()
{
    int n = 6;
    int m = 3;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    Solution sol = Solution();

    sol.merge(nums1, m, nums2, m);

    cout << "Merged Array: " << endl;

    for (int i = 0; i < m + n; i++)
    {
        cout << nums1[i] << " ";
    }
}