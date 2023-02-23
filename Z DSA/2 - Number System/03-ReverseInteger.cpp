#include <iostream>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        int reverseNumber = 0;
        while (x != 0)
        {
            int temp = x % 10;
            if ((reverseNumber > INT_MAX / 10) || (reverseNumber < INT_MIN / 10))
                return 0;
            reverseNumber = reverseNumber * 10 + temp;
            x = x / 10;
        }
        return reverseNumber;
    }
};

int main()
{
    Solution sol = Solution();
    cout << "Reverse Number: " << sol.reverse(-123) << endl;
}