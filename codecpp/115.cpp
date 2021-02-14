#include "header.h"

#define ll long long
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        vector<vector<ll>> dp(2, vector<ll>(s.size(), 0));
        ll sum;
        for (int i = 0; i < t.size(); ++i)
        {
            fill(dp[i & 1].begin(), dp[i & 1].end(), 0);
            sum = 0;
            for (int j = 0; j < s.size(); ++j)
            {
                if (s[j] == t[i])
                {
                    if (i == 0)
                    {
                        dp[i & 1][j] = 1;
                    }
                    else
                    {
                        dp[i & 1][j] = sum;
                    }
                }
                sum += dp[(i + 1) & 1][j];
                if (sum>INT_MAX){
                    break;
                }
            }
        }
        sum = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            sum += dp[(t.size() - 1) & 1][i];
        }
        return sum;
    }
};

int main()
{
    Solution s;
    cout << s.numDistinct("a", "") << endl;
    return 0;
}