#include "header.h"

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int last = prices[0];
        int ans = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] < prices[i - 1])
            {
                if (prices[i - 1] > last)
                {
                    ans += prices[i - 1] - last;
                    last = prices[i];
                }
                else
                {

                    last = min(last, prices[i]);
                }
            }
        }
        if (prices[prices.size() - 1] > last)
        {
            ans += prices[prices.size() - 1] - last;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> prices = {1, 2, 3, 4, 5};
    cout << s.maxProfit(prices);
    return 0;
}