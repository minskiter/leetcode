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
    int beautySum(string s)
    {
        int ans = 0;
        for (int l = 0; l < s.size(); ++l)
        {
            vector<int> buffer(26, 0);
            multiset<int> vis;
            for (int r = l; r < s.size(); ++r)
            {
                if (buffer[s[r] - 'a'] > 0)
                    vis.erase(vis.find(buffer[s[r] - 'a']));
                buffer[s[r] - 'a']++;
                vis.emplace(buffer[s[r] - 'a']);
                ans += *vis.rbegin() - *vis.begin();
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}