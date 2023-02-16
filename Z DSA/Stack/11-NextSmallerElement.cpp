#include <bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/next-smaller-element_1112581

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> nextSmaller(n);
    stack<int> st;
    st.push(-1);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (st.top() >= curr)
        {
            st.pop();
        }
        nextSmaller[i] = st.top();
        st.push(curr);
    }

    return nextSmaller;
}

int main()
{
    int n = 3;
    vector<int> arr = {2, 3, 1};

    vector<int> nextSmaller = nextSmallerElement(arr, 3);

    for (int i = 0; i < n; i++)
    {
        cout << nextSmaller[i] << " ";
    }
}