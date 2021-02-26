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
    string shortestPalindrome(string s)
    {
        string rev = s;
        reverse(rev.begin(), rev.end());
        int maxmatch = 1;
        vector<int> pre(s.size() + 1, -1);
        int j = -1;
        rep(i, 1, s.size() - 1, 1)
        {
            while (j != -1 && s[j + 1] != s[i])
                j = pre[j];
            if (s[j + 1] == s[i])
                ++j;
            pre[i] = j;
        }
        j = -1;
        rep(i, 0, s.size() - 1, 1)
        {
            while (j != -1 && s[j + 1] != rev[i])
                j = pre[j];
            if (s[j + 1] == rev[i])
                ++j;
            if (i == s.size() - 1)
                return rev + s.substr(j + 1, s.size() - j);
        }
        return s;
    }
};

int main()
{
    cout << Solution().shortestPalindrome("aaaecaaa");
    return 0;
}