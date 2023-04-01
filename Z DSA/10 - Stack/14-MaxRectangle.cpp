#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

// https://practice.geeksforgeeks.org/problems/max-rectangle/1

class Solution
{
private:
    vector<int> findNextSmallerElement(int *arr, int n)
    {
        vector<int> nextSmaller(n);
        stack<int> st;
        st.push(-1);

        for (int i = n - 1; i >= 0; i--)
        {
            int curr = arr[i];

            while (st.top() != -1 && arr[st.top()] >= curr)
            {
                st.pop();
            }

            nextSmaller[i] = st.top();
            st.push(i);
        }

        return nextSmaller;
    }

    vector<int> findPrevSmallerElement(int *arr, int n)
    {
        vector<int> prevSmaller(n);
        stack<int> st;
        st.push(-1);

        for (int i = 0; i < n; i++)
        {
            int curr = arr[i];

            while (st.top() != -1 && arr[st.top()] >= curr)
            {
                st.pop();
            }

            prevSmaller[i] = st.top();
            st.push(i);
        }

        return prevSmaller;
    }

    int largestRectangleArea(int *heights, int n)
    {
        vector<int> nextSmaller = findNextSmallerElement(heights, n);
        vector<int> prevSmaller = findPrevSmallerElement(heights, n);
        int area = -1;

        for (int i = 0; i < n; i++)
        {
            int l = heights[i];
            if (nextSmaller[i] == -1)
            {
                nextSmaller[i] = n;
            }
            int b = nextSmaller[i] - prevSmaller[i] - 1;

            int newArea = l * b;

            area = max(area, newArea);
        }

        return area;
    }

public:
    int maxArea(int M[MAX][MAX], int n, int m)
    {
        // compute area for first row
        int area = largestRectangleArea(M[0], m);

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (M[i][j] != 0)
                {
                    M[i][j] = M[i][j] + M[i - 1][j];
                }
                else
                {
                    M[i][j] = 0;
                }
            }
            area = max(area, largestRectangleArea(M[i], m));
        }

        return area;
    }
};

int main()
{
    int n = 4;
    int m = 4;
    int M[][MAX] = {{0, 1, 1, 0},
                    {1, 1, 1, 1},
                    {1, 1, 1, 1},
                    {1, 1, 0, 0}};

    Solution ob;
    cout << "Max area: " << ob.maxArea(M, n, m) << endl;
}