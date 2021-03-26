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
    int getMoneyAmount(int n)
    {
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        for (int len = 0; len < n; ++len)
        {
            for (int l = 0; l < n - len; ++l)
            {
                int r = l + len;
                if (len == 0)
                    dp[l][r] = 0;
                else
                    for (int root = l; root <= r; ++root)
                    {
                        if (root == l)
                        {
                            dp[l][r] = min(dp[l][r], root + 1 + dp[root + 1][r]);
                        }
                        else if (root == r)
                        {
                            dp[l][r] = min(dp[l][r], dp[l][root - 1] + root + 1);
                        }
                        else
                            dp[l][r] = min(dp[l][r], max(dp[l][root - 1] + root + 1, dp[root + 1][r] + root + 1));
                    }
            }
        }
        return dp[0][n - 1];
    }
};

int main()
{
    cout << Solution().getMoneyAmount(2);
    return 0;
}