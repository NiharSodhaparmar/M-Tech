#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Given an array of integers arr, return true if the number of occurrences of each value in the array is unique, or false otherwise.

arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.

Input: arr = [1,2]
Output: false

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true
*/

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> numberOfOccurances;

        sort(arr.begin(), arr.end());

        int i = 0;
        while (i < n)
        {
            int count = 1;

            for (int j = i + 1; j < arr.size(); j++)
            {
                if (arr[i] == arr[j])
                {
                    count++;
                }
                else
                {
                    break;
                }
            }

            numberOfOccurances.push_back(count);
            i = i + count;
        }

        sort(numberOfOccurances.begin(), numberOfOccurances.end());

        for (int i = 0; i < numberOfOccurances.size() - 1; i++)
        {
            if (numberOfOccurances[i] == numberOfOccurances[i + 1])
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    vector<int> a = {1, 2};
    Solution sol = Solution();
    cout << "Array has unique number of occurances?: " << sol.uniqueOccurrences(a) << endl;
}