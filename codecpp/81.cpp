#include "header.h"

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1, mid;
        while (l <= r)
        {
            mid = (l + r) >> 1;
            if (nums[mid] == target)
            {
                return true;
            }

            if (nums[l] < nums[mid])
            {
                if (nums[l] <= target && nums[mid] >= target)
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else if (nums[mid] < nums[r])
            {
                if (nums[mid] <= target && nums[r] >= target)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }else{
                while (l<=r && nums[l]==nums[mid]) ++l;
                while (l<=r && nums[r]==nums[mid]) --r;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 0, 1, 1, 1};
    cout << s.search(nums, 0);
    return 0;
}