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
    int superPow(int a, vector<int> &b)
    {
        int ans = 1, cycle = a % 1337;
        a %= 1337;
        for (int i = b.size() - 1; i >= 0; --i)
        {
            for (int j = 0; j < b[i]; ++j)
                ans = (ans * a) % 1337;
            for (int j = 1; j < 10; ++j)
                cycle = (cycle * a) % 1337;
            a = cycle;
        }
        return ans;
    }
};

int main()
{
    vector<int> b{2, 0, 0};
    cout << Solution().superPow(2147483647, b);
    return 0;
}