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
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
const int BAD_VERSION = 4;

int isBadVersion(int m)
{
    if (m >= BAD_VERSION)
        return true;
    return false;
}

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int l = 0, r = n, mid;
        while (l < r)
        {
            mid = l + (r - l) / 2;
            if (!isBadVersion(mid))
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};

int main()
{
    return 0;
}