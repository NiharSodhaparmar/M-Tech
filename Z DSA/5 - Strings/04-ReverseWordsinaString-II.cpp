#include <iostream>
using namespace std;

/*
Input: s = "the sky is blue"
Output: "eht yks si eulb"
*/

class Solution
{
private:
    string reverseString(string s)
    {
        string ans = "";
        for (int i = s.length() - 1; i >= 0; i--)
        {
            ans += s[i];
        }
        return ans;
    }

public:
    string reverseWords(string s)
    {
        int n = s.length();
        string ans = "";
        string temp = "";
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ' ')
            {
                ans += reverseString(temp) + " ";
                temp = "";
            }
            else
            {
                temp += s[i];
            }
        }
        if (temp != "")
            ans += reverseString(temp);

        return ans;
    }
};

int main()
{
    string s = "the sky is blue";
    Solution sol = Solution();
    cout << "Reversed word string: " << sol.reverseWords(s);
}