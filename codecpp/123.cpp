#include "header.h"

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minLeft = 0, minRight = -1, maxAns = 0, minIndex = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] - prices[minIndex] > maxAns)
            {
                maxAns = prices[i] - prices[minIndex];
                minRight = i;
                minLeft = minIndex;
            }
            if (prices[minIndex] > prices[i])
            {
                minIndex = i;
            }
        }
        int minium = prices[0], pans = 0;
        for (int i = 1; i < minLeft; ++i)
        {
            pans = max(pans, prices[i] - minium);
            minium = min(minium, prices[i]);
        }
        maxAns += pans;
        if (minRight + 1 < prices.size() && minRight > -1)
        {
            pans = 0, minium = prices[minRight + 1];
            for (int i = minRight + 2; i < prices.size(); ++i)
            {
                pans = max(pans, prices[i] - minium);
                minium = min(minium, prices[i]);
            }
            maxAns = max(maxAns, prices[minRight] - prices[minLeft] + pans);
        }
        if (minLeft + 1 < prices.size() && minRight > -1)
        {
            minium = prices[minLeft + 1], pans = 0;
            for (int i = minLeft + 2; i < minRight; ++i)
            {
                pans = max(pans, minium - prices[i]);
                minium = max(minium, prices[i]);
            }
            maxAns = max(maxAns, prices[minRight] - prices[minLeft] + pans);
        }
        return maxAns;
    }
};

int main()
{
    vector<int> prices = {2, 4, 1};
    Solution s;
    cout << s.maxProfit(prices);
    return 0;
}