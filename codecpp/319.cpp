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

// 0
// 1   1
// 1
// 1   
// 2   4
// 2
// 2
// 2
// 2
// 3   9
// 3
// 3
// 3
// 3
// 3
// 3   
// 4   16
// 4
// 4
// 4
// Solution Here
class Solution
{
public:
    int bulbSwitch(int n)
    {
        // 找规律
        // vector<bool> s(n, true);
        // for (int i = 1; i < n; ++i)
        // {
        //     for (int j = i; j < n; j += i + 1)
        //         s[j] = s[j] ^ true;
        // }
        // int ans = 0;
        // for (int i = 0; i < n; ++i)
        // {
        //     if (s[i])
        //         ++ans;
        // }
        // return ans;
        return sqrt(n);
    }
};

int main()
{
    
}