#include <iostream>
using namespace std;

/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

Example 1:
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:
Input: s1 = "ab", s2 = "eidboaoo"
Output: false
*/

class Solution
{
private:
    bool checkEqual(int count1[], int count2[])
    {
        for (int i = 0; i < 26; i++)
        {
            if (count1[i] != count2[i])
            {
                return false;
            }
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2)
    {
        int count1[26] = {0};
        int length1 = s1.length();
        int length2 = s2.length();

        for (int i = 0; i < length1; i++)
        {
            count1[s1[i] - 'a']++;
        }

        int i = 0;
        int count2[26] = {0};

        while (i < length1 && i < length2)
        {
            count2[s2[i] - 'a']++;
            i++;
        }

        if (checkEqual(count1, count2))
        {
            return true;
        }

        while (i < length2)
        {
            count2[s2[i] - 'a']++;
            count2[s2[i - length1] - 'a']--;
            i++;

            if (checkEqual(count1, count2))
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    string s1 = "ab";
    string s2 = "eidboaoo";
    Solution sol = Solution();
    cout << "Permutation is in string?: " << (sol.checkInclusion(s1, s2) ? "TRUE" : "FALSE") << endl;
}