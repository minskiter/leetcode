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
// TODO: 单调队列
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        multiset<int> window;
        for (int i = 0; i < k; ++i)
            window.insert(nums[i]);
        vector<int> res{*window.rbegin()};
        for (int i = k; i < nums.size(); ++i)
        {
            window.insert(nums[i]);
            window.erase(window.find(nums[i - k]));
            res.emplace_back(*window.rbegin());
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {-7,-8,7,5,7,1,6,0};
    cout << Solution().maxSlidingWindow(nums,4);
    return 0;
}