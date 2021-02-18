#include "header.h"

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size(), false);
        for (int i = 0; i < s.size(); ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                if (wordSet.find(s.substr(j, i - j + 1)) != wordSet.end())
                    dp[i] = dp[i] || (j == 0 || dp[j - 1]);
            }
        }
        return dp[s.size() - 1];
    }
};

int main()
{
    Solution s;
    vector<string> wordDict = {"aaaa","aaa"};
    cout << s.wordBreak("aaaaaaa",wordDict);
    return 0;
}