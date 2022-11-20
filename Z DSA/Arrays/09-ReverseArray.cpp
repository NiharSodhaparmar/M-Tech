#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void reverseString(vector<int> &s)
    {
        int start = 0;
        int end = s.size() - 1;

        while (start <= end)
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
};

int main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    Solution sol = Solution();

    sol.reverseString(a);

    cout << "Reverse Array: " << endl;

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
}