#include "header.h"

#define ll long long
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        set<ll> isExists;
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                int l = j + 1, r = nums.size() - 1;
                while (l < r)
                {
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum > target)
                    {
                        r--;
                    }
                    else if (sum < target)
                    {
                        l++;
                    }
                    else
                    {
                        ll flag = (ll)nums[i] * 1e10 + (ll)nums[j] * 1e5 + (ll)nums[l];
                        if (isExists.find(flag) == isExists.end())
                        {
                            isExists.insert(flag);
                            vector<int> temp = {
                                nums[i], nums[j], nums[l], nums[r]};
                            ans.push_back(temp);
                        }
                        r--, l++;
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> test =
        {-2, -1, -1, 1, 1, 2, 2};
    fmt::printArray2(s.fourSum(test, 0));
    return 0;
}