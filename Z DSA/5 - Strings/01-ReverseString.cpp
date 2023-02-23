#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void reverseString(vector<char> &s)
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
    vector<char> a = {'n', 'i', 'h', 'a', 'r'};
    Solution sol = Solution();

    sol.reverseString(a);

    cout << "Reverse String: " << endl;

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
}