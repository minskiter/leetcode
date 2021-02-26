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
    int rob(vector<int> &nums)
    {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(2));
        rep(i, 1, nums.size(), 1)
        {
            if (i == 1)
            {
                dp[i][0] = 0;
                dp[i][1] = nums[i - 1];
            }
            else if (i != nums.size())
            {
                dp[i][0] = max(dp[i - 1][0], dp[i - 2][0] + nums[i - 1]);
                dp[i][1] = max(dp[i - 1][1], dp[i - 2][1] + nums[i - 1]);
            }
            else
            {
                dp[i][0] = max(dp[i - 1][0], dp[i - 2][0] + nums[i - 1]);
                dp[i][1] = dp[i - 1][1];
            }
        }
        return max(dp[nums.size()][0], dp[nums.size()][1]);
    }
};

int main()
{
    vector<int> nums = {0};
    cout << Solution().rob(nums) << endl;
    return 0;
}