#include "header.h"

class Solution
{
public:
    int minCut(string s)
    {
        vector<vector<bool>> cutPalindrome(s.size(), vector<bool>(s.size(), false));
        for (int i = 0; i < s.size(); ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                if (s[i] == s[j])
                {
                    if (i == j || i == j + 1 || cutPalindrome[j + 1][i - 1])
                    {
                        cutPalindrome[j][i] = true;
                    }
                }
            }
        }
        vector<int> dp(s.size(), s.size());
        for (int i = 0; i < s.size(); ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                if (cutPalindrome[j][i])
                {
                    dp[i] = min(dp[i], j ? dp[j - 1] + 1 : 0);
                }
            }
        }
        return dp[s.size() - 1];
    }
};

int main()
{
    Solution s;
    cout << s.minCut("a");
    return 0;
}