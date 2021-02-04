#include "header.h"

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        auto findBin = [](vector<int> &nums, int l, int r, int target) {
            int mid;
            while (l <= r)
            {
                mid = (l + r) >> 1;
                if (target > nums[mid])
                {
                    l = mid + 1;
                }
                else if (target == nums[mid])
                {
                    return mid;
                }
                else
                {
                    r = mid - 1;
                }
            }
            return -1;
        };
        int l = 0, r = nums.size() - 1, mid;
        while (l <= r)
        {
            mid = (l + r) >> 1;
            if (nums[mid]==target){
                return mid;
            }
            // 检查哪部分是有序的
            if (nums[l] < nums[mid])
            {
                // 左部分有序
                if (mid > 0 && nums[l] <= target && target <= nums[mid - 1])
                {
                    return findBin(nums, l, mid - 1, target);
                }
                l = mid + 1;
            }else
            {
                // 右半部分有序
                if (mid + 1 < nums.size() && nums[mid + 1] <= target && target <= nums[r])
                {
                    return findBin(nums, mid + 1, r, target);
                }
                r = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> test = {3,1};
    cout << s.search(test, 1);
    return 0;
}