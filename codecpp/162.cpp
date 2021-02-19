#include "header.h"

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1, mid;
        while (l < r)
        {
            mid = (l + r) >> 1;
            if (nums[mid] > nums[mid + 1])
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};

int main()
{
    vector<int> nums = {3, 2, 1};
    Solution s;
    cout << s.findPeakElement(nums) << endl;
    return 0;
}