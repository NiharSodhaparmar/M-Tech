#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/minimum-cost-to-make-string-valid_1115770

int findMinimumCost(string str)
{
    if (str.length() % 2 == 1)
    {
        return -1;
    }

    stack<char> st;

    for (int i = 0; i < str.length(); i++)
    {
        char bracket = str[i];

        if (bracket == '{')
        {
            st.push(bracket);
        }
        else
        {
            if (!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
            {
                st.push(bracket);
            }
        }
    }

    int open = 0, close = 0;

    while (!st.empty())
    {
        char bracket = st.top();
        st.pop();

        if (bracket == '{')
        {
            open++;
        }
        else
        {
            close++;
        }
    }

    return (((open + 1) / 2) + ((close + 1) / 2));
}

int main()
{
    string str = "{{{{}}}}}}";

    cout << "Minimum cost: " << findMinimumCost(str);
}