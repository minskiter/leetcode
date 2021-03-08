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

#define INF 0x3f3f3f3f
// Solution Here
class Solution
{
public:
    int numSquares(int n)
    {
        while (n % 4 == 0)
            n /= 4;
        if (n % 8 == 7)
        {
            return 4;
        }
        if (sqr((int)sqrt(n)) == n)
        {
            return 1;
        }
        for (int i = sqrt(n); i >= 1; --i)
        {
            if (sqr((int)sqrt(n - i * i)) == n - i * i)
            {
                return 2;
            }
        }
        return 3;
    }
};

int main()
{
    return 0;
}