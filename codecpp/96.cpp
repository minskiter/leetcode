#include "header.h"

class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> dp(n + 2);
        dp[1] = dp[0] = 1;
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 1; j <= i; ++j)
            {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution s;
    cout << s.numTrees(3);
    return 0;
}