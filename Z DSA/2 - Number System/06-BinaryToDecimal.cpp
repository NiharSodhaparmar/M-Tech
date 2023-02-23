#include <iostream>
#include <math.h>
using namespace std;

class Solution
{
public:
    int decimalToBin(int n)
    {
        int decimalNumber = 0;
        int i = 0;
        while (n != 0)
        {
            int digit = n % 10;
            if (digit == 1)
            {
                decimalNumber += pow(2, i);
            }
            n = n / 10;
            i++;
        }

        return decimalNumber;
    }
};

int main()
{
    Solution sol = Solution();
    cout << "Decimal Number: " << sol.decimalToBin(1000000) << endl;
}
