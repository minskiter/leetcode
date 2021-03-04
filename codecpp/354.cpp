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

bool cmp(const vector<int> &a, const vector<int> &b)
{
    if (a[0] < b[0])
        return true;
    if (a[0] == b[0] && a[1] < b[1])
        return true;
    return false;
}

// Solution Here
class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> dp(envelopes.size());
        int ans = 0;
        for (int i = 0; i < envelopes.size(); ++i)
        {
            dp[i] = 1;
            for (int j = 0; j < i; ++j)
            {
                if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> inputs = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};
    Solution().maxEnvelopes(inputs);
    return 0;
}