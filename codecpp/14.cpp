#include "header.h"

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int minLens = INT_MAX;
        for (int i = 0; i < strs.size(); ++i)
        {
            minLens = min<int>(minLens, strs[i].size());
        }
        string ans = "";
        if (strs.size() > 0)
            for (int j = 0; j < minLens; ++j)
            {
                char ch = strs[0][j];
                for (int i = 1; i < strs.size(); ++i)
                {
                    if (ch != strs[i][j])
                    {
                        return ans;
                    }
                }
                ans += ch;
            }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> str = {};
    cout << s.longestCommonPrefix(str);
}