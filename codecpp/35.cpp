#include "header.h"

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1, mid = 0;
        while (l <= r)
        {
            mid = (l + r) >> 1;
            if (nums[mid] < target)
            {
                l = mid + 1;
            }
            else if (nums[mid] == target)
            {
                return mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        if (nums[mid] > target)
        {
            return mid;
        }
        else
        {
            return mid + 1;
        }
    }
};

int main()
{
    Solution s;
    vector<int> test = {1, 3, 5, 6, 8};
    cout << s.searchInsert(test, 4) << endl;
    return 0;
}