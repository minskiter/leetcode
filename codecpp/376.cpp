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
    int wiggleMaxLength(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 1;
        int diff = nums[1] - nums[0];
        int ans = nums.size();
        if (diff == 0)
            ans--;
        for (int i = 2; i < nums.size(); ++i)
        {
            if (nums[i] - nums[i - 1] > 0 && diff > 0)
            {
                ans--;
            }
            else if (nums[i] - nums[i - 1] == 0)
            {
                ans--;
            }
            else if (nums[i] - nums[i - 1] < 0 && diff < 0)
            {
                ans--;
            }
            else
            {
                diff = nums[i] - nums[i - 1];
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}