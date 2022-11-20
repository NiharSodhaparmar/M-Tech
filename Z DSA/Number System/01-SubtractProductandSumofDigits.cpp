#include <iostream>
using namespace std;

class Solution
{
public:
    int subtractProductAndSum(int n)
    {
        int sum = 0;
        int product = 1;
        while (n)
        {
            int a = n % 10;
            sum += a;
            product *= a;
            n = n / 10;
        }

        return product - sum;
    }
};

int main()
{
    Solution sol = Solution();
    cout << "Subtraction of the Product and Sum of Digits of an Integer: " << sol.subtractProductAndSum(12) << endl;
}