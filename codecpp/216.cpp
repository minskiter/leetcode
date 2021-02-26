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
    void dfs(vector<vector<int>> &ansV, vector<int> &ans, int deepth, int sum, int target, int total)
    {
        if (deepth >= 9 || ans.size() == total)
        {
            if (ans.size() == total && sum == target)
                ansV.emplace_back(ans);
            return;
        }
        rep(i, deepth + 1, 9, 1)
        {
            ans.emplace_back(i);
            dfs(ansV, ans, i, sum + i, target, total);
            ans.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        if (n > 45)
            return vector<vector<int>>();
        vector<vector<int>> ansV;
        vector<int> ans;
        dfs(ansV, ans, 0, 0, n, k);
        return ansV;
    }
};

int main()
{
    fmt::printArray2(Solution().combinationSum3(3,9));
    return 0;
}