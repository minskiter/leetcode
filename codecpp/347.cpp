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
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        set<pair<int, int>> cnt;
        unordered_map<int, int> mapper;
        for (int i = 0; i < nums.size(); ++i)
        {
            auto tmp = ++mapper[nums[i]];
            if (tmp != 1)
            {
                cnt.erase(make_pair(tmp - 1, nums[i]));
            }
            cnt.emplace(make_pair(tmp, nums[i]));
        }
        vector<int> ans;
        auto ptr = cnt.rbegin();
        for (int i = 0; i < k; ++i)
        {
            ans.emplace_back(ptr->first);
            ptr = next(ptr);
        }
        return ans;
    }
};

int main()
{
    return 0;
}