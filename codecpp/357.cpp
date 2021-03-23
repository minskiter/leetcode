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
    int dfs(vector<bool> &s, int deepth, int &n, bool prefixZero)
    {
        if (deepth == n)
            return 1;
        int ans = 0;
        for (int i = 0; i < 10; ++i)
        {
            if (!s[i] || (i == 0 && !prefixZero))
            {
                s[i] = true;
                ans += dfs(s, deepth + 1, n, prefixZero | (i != 0));
                s[i] = false;
            }
        }
        return ans;
    }

public:
    int countNumbersWithUniqueDigits(int n)
    {
        vector<bool> s(10);
        return dfs(s, 0, n, false);
    }
};

int main()
{
    cout << Solution().countNumbersWithUniqueDigits(2) << endl;
    return 0;
}