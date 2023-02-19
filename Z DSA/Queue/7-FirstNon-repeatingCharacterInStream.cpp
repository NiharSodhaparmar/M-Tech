#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        unordered_map<char, int> freq;
        queue<char> q;
        string ans;

        for (int i = 0; i < A.length(); i++)
        {
            char ch = A[i];
            freq[ch]++;
            q.push(ch);

            while (!q.empty())
            {
                if (freq[q.front()] > 1)
                {
                    q.pop();
                }
                else
                {
                    ans.push_back(q.front());
                    break;
                }
            }

            if (q.empty())
            {
                ans.push_back('#');
            }
        }

        return ans;
    }
};

int main()
{
    string A = "aabc";

    Solution s;

    A = s.FirstNonRepeating(A);

    cout << A << endl;

    return 0;
}