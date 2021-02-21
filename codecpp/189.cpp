#include "header.h"

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        k = nums.size() - k % nums.size();
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

int main()
{
    vector<int> nums = {-1, -100, 3, 99};
    Solution().rotate(nums, 2);
    fmt::printArray(nums);
    return 0;
}