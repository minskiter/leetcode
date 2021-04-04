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

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[0] > b[0];
}
// Solution Here
class Solution
{
    int maxans = 1;
    void dfs(vector<vector<int>> &gcdarr, int ans, int vis, int pos, int deepth)
    {
        if (deepth == 0)
        {
            maxans = max(ans, maxans);
            return;
        }
        for (int i = pos; i < gcdarr.size(); ++i)
        {
            if (ans + deepth * (deepth + 1) / 2 * gcdarr[i][0] < maxans)
                break;
            if ((vis & (1 << gcdarr[i][1])) && (vis & (1 << gcdarr[i][2])))
            {
                dfs(gcdarr, ans + deepth * gcdarr[i][0], vis - (1 << gcdarr[i][1]) - (1 << gcdarr[i][2]), i + 1, deepth - 1);
            }
        }
    }

public:
    int maxScore(vector<int> &nums)
    {
        vector<vector<int>> gcdarr;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                vector<int> temp = {gcd(nums[i], nums[j]), i, j};
                gcdarr.emplace_back(temp);
            }
        }
        sort(gcdarr.begin(), gcdarr.end(), cmp);
        cout << gcdarr[0][0] << endl;
        dfs(gcdarr, 0, (1 << nums.size()) - 1, 0, nums.size() >> 1);
        return maxans;
    }
};

int main()
{
    return 0;
}