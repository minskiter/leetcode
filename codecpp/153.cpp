#include "header.h"

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1, mid;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (mid + 1 < nums.size() && nums[mid + 1] < nums[mid])
                return nums[mid + 1];
            if (mid > 0 && nums[mid] < nums[mid - 1])
                return nums[mid];
            if (nums[mid] < nums[l])
                r = mid;
            else if (nums[mid] > nums[r])
                l = mid;
            else
                return min(nums[l], nums[r]);
        }
        return min(nums[l], nums[r]);
    }
};

int main()
{
    vector<int> nums = {3, 4, 1};
    Solution s;
    cout << s.findMin(nums) << endl;
    return 0;
}