#include "header.h"

class Solution
{
public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<int> nxt, edges, head(s.size() + 1, -1), dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 0; i < s.size(); ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                if (wordSet.find(s.substr(j, i - j + 1)) != wordSet.end())
                {
                    edges.push_back(i + 1);
                    nxt.push_back(head[j]);
                    head[j] = nxt.size() - 1;
                    dp[i + 1] = dp[i + 1] || dp[j];
                }
            }
        }
        vector<string> ansV, ans;
        if (dp[s.size()])
            dfs(ansV, ans, s, head, nxt, edges);
        return ansV;
    }

private:
    void dfs(vector<string> &ansV, vector<string> &ans, string &s, vector<int> &head, vector<int> &nxt, vector<int> &edges, int deepth = 0)
    {
        if (deepth >= head.size() - 1)
        {
            string temp;
            for (int i = 0; i < ans.size(); ++i)
            {
                if (i != 0)
                    temp = temp + " ";
                temp = temp + ans[i];
            }
            ansV.push_back(temp);
            return;
        }
        int p = head[deepth];
        while (p != -1)
        {
            ans.push_back(s.substr(deepth, edges[p] - deepth));
            dfs(ansV, ans, s, head, nxt, edges, edges[p]);
            ans.pop_back();
            p = nxt[p];
        }
    }
};

int main()
{
    Solution s;
    vector<string> wordDict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    fmt::printArray(s.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", wordDict));
    return 0;
}