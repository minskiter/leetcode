#include "header.h"

#define rep(i, f, t, s) for (int i = f; i <= t; i += s)
#define repd(i, f, t, s) for (int i = f; i >= t; i -= s)
#define mk(a, b) make_pair(a, b)

// Solution Here
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size()==0) return 0;
        vector<int> dp(3, 0);
        for (int i = 0; i < nums.size(); ++i)
        {
            dp[i % 3] = max(dp[(i + 2) % 3], dp[(i + 1) % 3] + nums[i]);
        }
        return dp[(nums.size() - 1) % 3];
    }
};

int main()
{
    vector<int> nums = {2,7,9,3,1};
    cout << Solution().rob(nums);
    return 0;
}