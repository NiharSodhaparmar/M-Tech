#include <iostream>
#include <vector>
using namespace std;

// class Solution
// {
// public:
//     int countPrimes(int n)
//     {
//         vector<int> primeNumbers;
//         for (int i = 2; i < n; i++)
//         {
//             int flag = 0;
//             for (int j = 0; j < primeNumbers.size(); j++)
//             {

//                 if (i % primeNumbers[j] == 0)
//                 {
//                     flag = 1;
//                     break;
//                 }
//             }

//             if (flag)
//             {
//                 continue;
//             }
//             primeNumbers.push_back(i);
//         }

//         return primeNumbers.size();
//     }
// };

class Solution
{
public:
    int countPrimes(int n)
    {
        int primeNumbers = 0;
        vector<bool> prime(n + 1, true);

        for (int i = 2; i < n; i++)
        {
            if (prime[i])
            {
                primeNumbers++;

                for (int j = 2 * i; j < n; j = j + i)
                {
                    prime[j] = 0;
                }
            }
        }

        return primeNumbers;
    }
};

int main()
{
    Solution sol = Solution();
    int n = 40;
    cout << "Prime numbers < " << n << " : " << sol.countPrimes(n) << endl;
}