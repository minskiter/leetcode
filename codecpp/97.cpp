#include "header.h"

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.size() + s2.size() != s3.size())
        {
            return false;
        }
        vector<vector<bool>> dp(2, vector<bool>(s2.size() + 1));
        for (int i = 0; i <= s1.size(); ++i)
        {
            for (int j = 0; j <= s2.size(); ++j)
            {
                dp[i & 1][j] = false;
                if (i == 0 && j == 0)
                    dp[0][0] = true;
                else
                {
                    if (i > 0 && s1[i - 1] == s3[i + j - 1])
                    {
                        dp[i & 1][j] = dp[(i - 1) & 1][j];
                    }
                    if (j > 0 && s2[j - 1] == s3[i + j - 1])
                    {
                        dp[i & 1][j] = dp[i & 1][j] || dp[i & 1][j - 1];
                    }
                }
            }
        }
        return dp[s1.size() & 1][s2.size()];
    }
};

int main()
{
    Solution s;
    cout << s.isInterleave("aabcc", "dbbca", "aadbbcbcac");
    return 0;
}