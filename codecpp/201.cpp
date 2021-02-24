#include "header.h"

#define rep(i, f, t, s) for (int i = f; i <= t; i += s)
#define repd(i, f, t, s) for (int i = f; i >= t; i -= s)
#define mk(a, b) make_pair(a, b)
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

// Solution Here
class Solution
{
public:
    int rangeBitwiseAnd(int m, int n)
    {
        // 这个步骤可以直接修改为n&(n-1),即逐步去掉最低位
        int ans = 0;
        for (int i = 30; i >= 0; --i)
        {
            int l = 1 << i;
            int r = i == 30 ? INT_MAX : (1 << (i + 1)) - 1;
            if (ans + r >= n && ans + l <= m)
            {
                ans += l;
            }
        }
        return ans;
    }
};

int main()
{
    cout << Solution().rangeBitwiseAnd((1 << 30) + 5, (1 << 30) + 7);
    return 0;
}