#include "header.h"

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        vector<vector<int>> dp(2, vector<int>(p.size() + 1, INT_MIN));
        dp[0][0] = 0;
        for (int j = 1; j <= p.size(); ++j)
        {
            if (p[j - 1] == '*')
            {
                dp[0][j] = dp[0][j - 1];
            }
            else
            {
                break;
            }
        }
        for (int i = 1; i <= s.size(); ++i)
        {
            for (int j = 1; j <= p.size(); ++j)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                {
                    dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
                }
                else if (p[j - 1] == '*')
                {
                    dp[i % 2][j] = max(max(dp[(i - 1) % 2][j - 1], dp[(i - 1) % 2][j]) + 1, dp[i % 2][j - 1]);
                }
            }
        }
        return dp[s.size() % 2][p.size()] == s.size();
    }
};

int main()
{
    Solution s;
    cout << s.isMatch("", "?");
    return 0;
}