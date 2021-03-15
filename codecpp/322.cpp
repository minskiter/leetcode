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
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> bag(amount + 1, 0x3f3f3f3f);
        bag[0] = 0;
        for (int i = 0; i < amount; ++i)
        {
            for (int j = 0; j < coins.size(); ++j)
            {
                unsigned int bagPos = (unsigned int)i + (unsigned int)coins[j];
                if (bagPos <= (unsigned int)amount)
                    bag[bagPos] = min(bag[bagPos], bag[i] + 1);
            }
        }
        return bag[amount] == 0x3f3f3f3f ? -1 : bag[amount];
    }
};

int main()
{
    return 0;
}