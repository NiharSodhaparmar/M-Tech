#include <iostream>
#include <math.h>
using namespace std;

class Solution
{
public:
    int bitwiseComplement(int n)
    {
        int m = n;
        int mask = 0;

        if (n == 0)
            return 1;

        while (m != 0)
        {
            mask = (mask << 1) | 1;
            m = m >> 1;
        }

        return mask & (~n);
    }
};

int main()
{
    Solution sol = Solution();
    cout << "Complement Number: " << sol.bitwiseComplement(7) << endl;
}