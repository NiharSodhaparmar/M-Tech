#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
            return false;

        return (n & (n - 1)) == 0;
    }
};

int main()
{
    Solution sol = Solution();
    cout << "Is a power of two: " << sol.isPowerOfTwo(8) << endl;
}