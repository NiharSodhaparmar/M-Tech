#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        vector<int> price;
        for (int i = 0; i < prices.size() - 1; i++)
        {
            price.push_back(prices[i + 1] - prices[i]);
        }

        int sum = 0;
        int maxi = 0;

        for (int i = 0; i < price.size(); i++)
        {
            sum += price[i];

            if (sum > maxi)
            {
                maxi = sum;
            }

            if (sum < 0)
            {
                sum = 0;
            }
        }

        return maxi;
    }
};