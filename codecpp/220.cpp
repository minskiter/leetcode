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
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, long long t)
    {
        set<long long> exists;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > k)
                exists.erase(nums[i - k - 1]);
            if (!exists.empty())
            {
                auto itor = exists.lower_bound(nums[i]);
                if (itor != exists.end())
                {
                    if (abs((long long)*itor - nums[i]) <= t)
                        return true;
                }
                if (itor != exists.begin())
                {
                    itor = prev(itor);
                    if (abs((long long)*itor - nums[i]) <= t)
                        return true;
                }
            }
            exists.emplace(nums[i]);
        }
        return false;
    }
};

int main()
{
    vector<int> nums = {INT_MIN, INT_MAX};
    cout << Solution().containsNearbyAlmostDuplicate(nums, 1, 1);
    return 0;
}