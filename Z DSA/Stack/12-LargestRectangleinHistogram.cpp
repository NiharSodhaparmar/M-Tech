#include <iostream>
#include <stack>
#include <vector>
#include <math.h>
using namespace std;

class Solution
{
private:
    vector<int> findNextSmallerElement(vector<int> &arr, int n)
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

    vector<int> findPrevSmallerElement(vector<int> &arr, int n)
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

public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
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
};

int main()
{
    Solution s;

    vector<int> histogram = {2, 1, 5, 6, 2, 3};

    cout << "Largest area: " << s.largestRectangleArea(histogram) << endl;

    return 0;
}