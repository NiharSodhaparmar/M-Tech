#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

class Solution1
{
public:
    // Brute Force
    int celebrity(vector<vector<int>> &M, int n)
    {
        int celebrityIndex = -1;

        for (int i = 0; i < n; i++)
        {
            bool flag = true;

            for (int j = 0; j < n; j++)
            {
                if (M[i][j] != 0)
                {

                    flag = false;
                    break;
                }
            }

            if (flag == false)
            {
                continue;
            }

            for (int j = 0; j < n; j++)
            {
                if (i != j && M[j][i] != 1)
                {
                    flag = false;
                    break;
                }
            }

            if (flag == true)
            {
                return celebrityIndex = i;
            }
        }

        return celebrityIndex;
    }
};

class Solution
{
public:
    int celebrity(vector<vector<int>> &M, int n)
    {
        stack<int> s;

        for (int i = 0; i < n; i++)
        {
            s.push(i);
        }

        while (s.size() > 1)
        {
            int a = s.top();
            s.pop();

            int b = s.top();
            s.pop();

            if (M[a][b] == 1)
            {
                s.push(b);
            }
            else
            {
                s.push(a);
            }
        }

        int ans = s.top();

        for (int i = 0; i < n; i++)
        {
            if (i != ans && M[i][ans] != 1)
            {
                return -1;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (i != ans && M[ans][i] != 0)
            {
                return -1;
            }
        }

        return ans;
    }
};

int main()
{
    int n = 3;
    vector<vector<int>> M = {{0, 1, 0},
                             {0, 0, 0},
                             {0, 1, 0}};

    Solution ob;
    cout << ob.celebrity(M, n) << endl;
}