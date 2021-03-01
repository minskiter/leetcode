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
    vector<int> majorityElement(vector<int> &nums)
    {
        vector<int> ans;
        int f = 0, s = 0, fc = 0, sc = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if ((fc == 0 || nums[i] == f) && nums[i] != s)
            {
                ++fc;
                f = nums[i];
            }
            else if (sc == 0 || nums[i] == s)
            {
                ++sc;
                s = nums[i];
            }
            else
            {
                --fc;
                --sc;
            }
        }
        fc = 0, sc = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == f)
                ++fc;
            if (f!=s && nums[i] == s)
                ++sc;
        }
        if (fc > nums.size() / 3)
            ans.emplace_back(f);
        if (sc > nums.size() / 3)
            ans.emplace_back(s);
        return ans;
    }
};

int main()
{
    vector<int> nums = {9, 9, 9, 9, 6, 5, 4, 3, 2, 1};
    cout << Solution().majorityElement(nums);
    return 0;
}