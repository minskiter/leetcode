#include "header.h"

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        if (k==0 || prices.size()==0) return 0;
        vector<int> buys(k, INT_MIN / 2), sells(k);
        for (int i = 0; i < prices.size(); ++i)
        {
            for (int j = 0; j < k; ++j)
            {
                if (j == 0)
                    buys[j] = max(buys[j], - prices[i]);
                else
                    buys[j] = max(buys[j], sells[j - 1] - prices[i]);
                sells[j] = max(sells[j], buys[j] + prices[i]);
            }
        }
        return sells[k - 1];
    }
};

int main()
{
    vector<int> prices = {3,2,6,5,0,3};
    cout << Solution().maxProfit(2, prices);
    return 0;
}