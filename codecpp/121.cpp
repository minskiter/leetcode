#include "header.h"

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minPrice = prices[0];
        int ans = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            ans = max(ans,prices[i]-minPrice);
            minPrice = min(minPrice,prices[i]);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> prices = {7,1,5,3,6,4};
    cout << s.maxProfit(prices);
    return 0;
}