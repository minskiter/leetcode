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
    static vector<int> ugly;
    static int historyN;
    static vector<int> ptr;
    int nthUglyNumber(int n)
    {
        if (n <= 0)
            return 0;
        for (; historyN < n; ++historyN)
        {
            int a = ugly[ptr[0]] * 2, b = ugly[ptr[1]] * 3, c = ugly[ptr[2]] * 5;
            int mininum = min(a, min(b, c));
            if (a == mininum)
                ++ptr[0];
            if (b == mininum)
                ++ptr[1];
            if (c == mininum)
                ++ptr[2];
            ugly.emplace_back(mininum);
        }
        return ugly[n - 1];
    }
};

vector<int> Solution::ugly{1};
vector<int> Solution::ptr(3, 0);
int Solution::historyN = 1;

int main()
{
    cout << Solution().nthUglyNumber(1690);
    return 0;
}