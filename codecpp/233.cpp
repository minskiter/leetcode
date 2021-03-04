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
    int countDigitOne(int n)
    {
        vector<int> buffer = {
            1, 20};
        long long bitCnt = 0, tmp = n, oct = 10;
        for (int i = 2; i < 9; ++i)
        {
            oct *= 10;
            buffer.emplace_back(10 * buffer[i - 1] + oct);
        }
        oct = 1;
        while (tmp / 10)
        {
            ++bitCnt;
            tmp /= 10;
            oct *= 10;
        }
        int ans = 0, rest = n;
        oct *= 10;
        for (int i = bitCnt; i > 0; --i)
        {
            tmp = rest % oct / (oct / 10);
            ans += tmp * buffer[i - 1];
            if (tmp == 1)
                ans += rest % (oct / 10) + 1;
            else if (tmp > 1)
                ans += oct / 10;
            oct /= 10;
        }
        if (rest % 10)
            ++ans;
        return ans;
    }
};

int main()
{
    cout << Solution().countDigitOne(113);
    return 0;
}