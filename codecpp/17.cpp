#include "header.h"

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> nums = {
            "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        for (int i = 0; i < digits.size(); ++i)
        {
            int num = digits[i] - '2';
            int last = ans.size();
            for (int j = 1; j < nums[num].size(); ++j)
            {
                for (int l = 0; l < last; ++l)
                {
                    string temp = ans[l];
                    ans.push_back(temp.append(1,nums[num][j]));
                }
            }
            for (int j = 0; j < last; ++j)
            {
                ans[j].append(1,nums[num][0]);
            }
            if (last == 0)
            {
                for (int j = 0; j < nums[num].size(); ++j)
                {
                    string temp = "";
                    ans.push_back(temp.append(1, nums[num][j]));
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    fmt::printArray<string>(s.letterCombinations("23"));
    return 0;
}