#include <iostream>
#include <stack>
using namespace std;

// https://leetcode.com/problems/valid-parentheses/

class Solution
{
public:
    bool isMatches(char top, char ch)
    {
        return ((top == '(' && ch == ')') || (top == '{' && ch == '}') || (top == '[' && ch == ']'));
    }

    bool isValid(string s)
    {
        stack<char> st;

        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];

            if (ch == '(' || ch == '{' || ch == '[')
            {
                st.push(ch);
            }
            else
            {
                if (!st.empty())
                {
                    char top = st.top();

                    if (isMatches(top, ch))
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }

        if (st.empty())
        {
            return true;
        }

        return false;
    }
};

int main()
{
    Solution sol = Solution();
    string s = "()[]{}";

    cout << "Is valid Parentheses?: " << (sol.isValid(s) ? "True" : "False") << endl;

    return 0;
}