#include <iostream>
#include <math.h>
using namespace std;

class Solution
{
public:
    int decimalToBin(int n)
    {
        n = abs(n);
        int binaryNumber = 0;
        int i = 0;
        while (n != 0)
        {
            int bit = n & 1;
            cout << "b: " << ~(bit) << endl;
            binaryNumber = (bit * pow(10, i)) + binaryNumber;
            n = n >> 1;
            i++;
        }

        return binaryNumber;
    }
};

int main()
{
    Solution sol = Solution();
    cout << "Binary Number: " << sol.decimalToBin(-10) << endl;
}
