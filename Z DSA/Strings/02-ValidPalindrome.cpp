#include <iostream>
using namespace std;

/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.


*/

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int n = s.length();
        string temp = "";
        for (int i = 0; i < s.length(); i++)
        {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
                temp += tolower(s[i]);
            else if (s[i] >= '0' && s[i] <= '9')
                temp += s[i];
        }

        int i = 0;
        int j = temp.length() - 1;

        while (i <= j)
        {
            if (temp[i] != temp[j])
                return false;

            i++;
            j--;
        }
        return true;
    }
};

int main()
{
    string s = "0P";
    Solution sol = Solution();
    cout << "String is Palindrome?: " << (sol.isPalindrome(s) ? "TRUE" : "FALSE");
}