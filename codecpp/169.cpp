#include "header.h"

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int cnt = 0, num = nums[0];
        for (auto n : nums)
        {
            if (n == num)
                cnt++;
            else
                cnt--;
            if (cnt < 0)
            {
                cnt = 1;
                num = n;
            }
        }
        return num;
    }
};

int main()
{
    vector<int> nums = {6, 5, 5};
    cout << Solution().majorityElement(nums) << endl;
    return 0;
}