#include "header.h"

#define rep(i, f, t, s) for (long long i = f; i <= (long long)t; i += s)
#define repd(i, f, t, s) for (long long i = f; i >= (long long)t; i -= s)
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
    long long computeArea(long long A, long long B, long long C, long long D, long long E, long long F, long long G, long long H)
    {
        long long a = (C - A) * (D - B), b = (G - E) * (H - F);
        long long h = min(G, C) - max(A, E), w = min(H, D) - max(F, B);
        if (h < 0 || w < 0)
            return a + b;
        return a - h * w + b;
    }
};

int main()
{
    cout << Solution().computeArea(-2, -2, 2, 2, -1, 4, 1, 6);
    return 0;
}