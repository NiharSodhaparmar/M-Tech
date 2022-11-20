#include <iostream>
using namespace std;

/*
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

Input: s = "the sky is blue"
Output: "blue is sky the"

*/

class Solution
{

public:
    string reverseWords(string s)
    {
        int i = 0;
        int n = s.length();
        string ans = "";

        while (i < n)
        {
            while (i < n && s[i] == ' ')
                i++;

            if (i >= n)
                break;

            int j = i;

            while (j < n && s[j] != ' ')
                j++;

            string subStr = s.substr(i, j - i);

            if (subStr.length() == 0)
                ans = subStr;
            else
                ans = " " + subStr + ans;

            i = j + 1;
        }

        // remove trailing spaces
        i = 0;
        while (i < n && ans[i] == ' ')
            i++;
        ans = ans.substr(i);

        return ans;
    }
};

int main()
{
    string s = "the sky is blue";
    Solution sol = Solution();
    cout << "Reversed word string: " << sol.reverseWords(s);
}