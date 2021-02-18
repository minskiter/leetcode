#include "header.h"

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int one = 0, two = 0;
        for (auto num : nums)
        {
            one = (one ^ num) & ~two;
            two = (two ^ num) & ~one;
        }
        return one;
    }
};

int main()
{
    vector<int> nums = {0,1,0,1,0,1,99};
    Solution s;
    cout << s.singleNumber(nums);
    return 0;
}