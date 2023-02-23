#include <iostream>
using namespace std;

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;
        while (n != 0)
        {
            if (n & 1)
            {
                count++;
            }
            n = n >> 1;
        }
        return count;
    }
};

int main()
{
    Solution sol = Solution();
    cout << "Number of 1 bits: " << sol.hammingWeight(00000000000000000000000010000000) << endl;
}