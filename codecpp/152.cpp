#include "header.h"

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        int l = 0, r;
        int maxinum = nums[0];
        for (r = 0; r < nums.size(); ++r)
        {
            if (nums[r] == 0)
            {
                if (l != r)
                    maxinum = max(maxinum, getMax(nums, l, r - 1));
                maxinum = max(0, maxinum);
                l = r + 1;
            }
        }
        if (l != r)
            maxinum = max(maxinum, getMax(nums, l, r - 1));
        return maxinum;
    }

private:
    int getMax(vector<int> &nums, int l, int r)
    {
        if (l == r)
            return nums[l];
        int maxinum = nums[l], i;
        for (i = l + 1; i <= r; ++i)
            maxinum *= nums[i];
        if (maxinum > 0)
            return maxinum;
        int lans = maxinum, rans = maxinum;
        for (i = l; i < r && nums[i] > 0; ++i)
            lans /= nums[i];
        if (i < r)
            lans /= nums[i];
        for (i = r; i > l && nums[i] > 0; --i)
            rans /= nums[i];
        if (i > l)
            rans /= nums[i];
        return max(lans, rans);
    }
};

int main()
{
    vector<int> nums = {-2, 0, -1};
    Solution s;
    cout << s.maxProduct(nums);
    return 0;
}