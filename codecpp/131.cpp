#include "header.h"

class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<bool>> isPalindrome(s.size(), vector<bool>(s.size(), false));
        for (int i = 0; i < s.size(); ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                if (s[i] == s[j])
                {
                    if (i == j || i == j + 1 || isPalindrome[j + 1][i - 1])
                    {
                        isPalindrome[j][i] = true;
                    }
                }
            }
        }
        vector<vector<string>> ansV;
        vector<string> ans;
        search(ansV, ans, s, isPalindrome);
        return ansV;
    }

private:
    void search(vector<vector<string>> &ansV, vector<string> &ans, string &s, vector<vector<bool>> &isPalindrome, int deepth = 0)
    {
        if (deepth >= s.size())
        {
            ansV.push_back(ans);
            return;
        }
        for (int i = deepth; i < s.size(); ++i)
        {
            if (isPalindrome[deepth][i])
            {
                ans.push_back(s.substr(deepth, i - deepth + 1));
                search(ansV, ans, s, isPalindrome, i + 1);
                ans.pop_back();
            }
        }
    }
};

int main()
{
    Solution s;
    fmt::printArray2(s.partition("efe"));
    return 0;
}