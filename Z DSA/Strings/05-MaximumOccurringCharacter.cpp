#include <iostream>
using namespace std;

class Solution
{
public:
    // Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        int a[26] = {0};

        for (int i = 0; i < str.size(); i++)
        {
            int index = -1;
            if (str[i] >= 'a' || str[i] <= 'z')
            {
                index = str[i] - 'a';
            }
            else if (str[i] >= 'A' || str[i] <= 'Z')
            {
                index = str[i] - 'A';
            }

            a[index]++;
        }

        int maxElement = INT_MIN;
        int maxIndex = -1;

        for (int i = 0; i < 26; i++)
        {
            if (a[i] > maxElement)
            {
                maxElement = a[i];
                maxIndex = i;
            }
        }

        return maxIndex + 'a';
    }
};

int main()
{
    string s = "the sky is blue";
    Solution sol = Solution();
    cout << "Maximum occuring character: " << sol.getMaxOccuringChar(s);
}