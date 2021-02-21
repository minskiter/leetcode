#include "header.h"

bool cmp(int a, int b)
{
    vector<int> as, bs;
    if (a == 0)
        as.emplace_back(a);
    while (a)
    {
        as.emplace_back(a % 10);
        a /= 10;
    }
    if (b == 0)
        bs.emplace_back(b);
    while (b)
    {
        bs.emplace_back(b % 10);
        b /= 10;
    }
    auto tmp = vector<int>(as.begin(), as.end());
    as.insert(as.end(), bs.begin(), bs.end());
    bs.insert(bs.end(), tmp.begin(), tmp.end());
    int len = as.size();
    for (int i = len - 1; i >= 0; --i)
    {
        if (as[i] == bs[i])
            continue;
        return as[i] < bs[i];
    }
    return false;
}

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), cmp);
        string ans;
        for (auto num : nums)
        {
            if (num == 0)
                ans.append("0");
            else
            {
                string tmp;
                while (num)
                {
                    tmp = char(num % 10 + '0') + tmp;
                    num /= 10;
                }
                ans.append(tmp);
            }
        }
        while (ans.size() > 1 && ans[0] == '0')
            ans.erase(ans.begin());
        return ans;
    }
};

int main()
{
    vector<int> nums = {0,0,0,1};
    cout << Solution().largestNumber(nums);
    return 0;
}