#include "header.h"

#define rep(i, f, t, s) for (int i = f; i <= (int)t; i += s)
#define repd(i, f, t, s) for (int i = f; i >= (int)t; i -= s)
#define mk(a, b) make_pair(a, b)
#define sqr(a) ((a) * (a))
template <class Ty1, class Ty2>
inline const pair<Ty1, Ty2> operator+(const pair<Ty1, Ty2> &p1, const pair<Ty1, Ty2> &p2)
{
    return mk(p1.first + p2.first, p1.second + p2.second);
}
template <class Ty1, class Ty2>
inline const pair<Ty1, Ty2> operator-(const pair<Ty1, Ty2> &p1, const pair<Ty1, Ty2> &p2)
{
    return mk(p1.first - p2.first, p1.second - p2.second);
}
template <class Ty1, class Ty2>
bool inner(pair<Ty1, Ty2> pos, pair<Ty1, Ty2> leftTop, pair<Ty1, Ty2> rightBottom)
{
    if (pos.first >= leftTop.first && pos.second >= leftTop.second)
    {
        if (pos.first < rightBottom.first && pos.second < rightBottom.second)
        {
            return true;
        }
    }
    return false;
}

// Solution Here
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        vector<int> buys = {-prices[0],0}, sells(2), colldowns(2);
        for (int i = 1; i < prices.size(); ++i)
        {
            buys[i & 1] = sells[i & 1] = colldowns[i & 1] = 0;
            buys[i & 1] = max(buys[(i + 1) & 1], colldowns[(i + 1) & 1] - prices[i]);
            sells[i & 1] = max(sells[(i + 1) & 1], buys[(i + 1) & 1] + prices[i]);
            colldowns[i & 1] = max(sells[(i + 1) & 1], colldowns[(i + 1) & 1]);
        }
        return sells[(prices.size()-1) & 1];
    }
};

int main()
{
    vector<int> prices = {1, 2, 3, 0, 2};
    cout << Solution().maxProfit(prices);
    return 0;
}