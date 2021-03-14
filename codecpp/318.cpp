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
    int maxProduct(vector<string> &words)
    {
        vector<pair<int, int>> cnt(words.size());
        for (int i = 0; i < words.size(); ++i)
        {
            for (int j = 0; j < words[i].size(); ++j)
            {
                cnt[i].first |= 1 << (words[i][j] - 'a');
            }
            cnt[i].second = words[i].size();
        }
        int ans = 0;
        for (int i = 0; i < cnt.size(); ++i)
        {
            for (int j = i + 1; j < cnt.size(); ++j)
            {
                if (!(cnt[i].first & cnt[j].first))
                    ans = max(ans, cnt[i].second * cnt[j].second);
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}