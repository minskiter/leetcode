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
class AuthenticationManager
{
    int _timeToLive;
    unordered_map<string, int> cnt;

public:
    AuthenticationManager(int timeToLive) : _timeToLive(timeToLive)
    {
    }

    void generate(string tokenId, int currentTime)
    {
        cnt[tokenId] = currentTime + _timeToLive;
    }

    void renew(string tokenId, int currentTime)
    {
        if (cnt.find(tokenId) != cnt.end())
        {
            if (cnt[tokenId] > currentTime)
            {
                cnt[tokenId] = currentTime + _timeToLive;
            }
            else
            {
                cnt.erase(tokenId);
            }
        }
    }

    int countUnexpiredTokens(int currentTime)
    {
        vector<string> removes;
        int ans = 0;
        for (auto [key, value] : cnt)
        {
            if (value > currentTime)
            {
                ans++;
            }
            else
            {
                removes.emplace_back(key);
            }
        }
        for (int i = 0; i < removes.size(); ++i)
        {
            cnt.erase(removes[i]);
        }
        return ans;
    }
};

int main()
{
    return 0;
}