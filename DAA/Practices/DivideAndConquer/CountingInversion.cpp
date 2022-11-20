#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int merge(vector<int> &arr, int start, int end, int mid)
    {
        int inversionCount = 0;
        int length1 = mid - start + 1;
        int length2 = end - mid;

        int *firstArray = new int[length1];
        int *secondArray = new int[length2];

        for (int i = 0; i < length1; i++)
        {
            firstArray[i] = arr[start + i];
        }

        for (int j = 0; j < length2; j++)
        {
            secondArray[j] = arr[mid + j + 1];
        }

        int mainArrayIndex = start;
        int index1 = 0;
        int index2 = 0;

        while (index1 < length1 && index2 < length2)
        {
            if (firstArray[index1] < secondArray[index2])
            {
                arr[mainArrayIndex++] = firstArray[index1++];
            }
            else
            {
                arr[mainArrayIndex++] = secondArray[index2++];
                inversionCount += (length1 - index1);
            }
        }

        while (index1 < length1)
        {
            arr[mainArrayIndex++] = firstArray[index1++];
        }

        while (index2 < length2)
        {
            arr[mainArrayIndex++] = secondArray[index2++];
        }

        delete[] firstArray;
        delete[] secondArray;

        return inversionCount;
    }

    int mergeSort(vector<int> &arr, int start, int end)
    {
        int inversionCount = 0;
        if (start >= end)
        {
            return inversionCount;
        }

        int mid = start + (end - start) / 2;

        inversionCount += mergeSort(arr, start, mid);
        inversionCount += mergeSort(arr, mid + 1, end);
        inversionCount += merge(arr, start, end, mid);

        return inversionCount;
    }

    int localInversion(vector<int> &nums, int n)
    {
        int localInversion = 0;

        return localInversion;
    }

public:
    bool isIdealPermutation(vector<int> &nums)
    {
        if (nums.size() < 2)
            return true;

        int localInversionCount = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i + 1])
                localInversionCount++;
        }

        int n = nums.size() - 1;
        int globalInversionCount = mergeSort(nums, 0, n);

        return localInversionCount == globalInversionCount;
    }
};

int main()
{
    vector<int> nums = {1, 0, 2};
    Solution s;
    cout << s.isIdealPermutation(nums) << endl;
}