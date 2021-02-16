#include "header.h"

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> numset(nums.begin(), nums.end());
        int left, right, longest = 0;
        for (auto num : nums)
        {
            left = num, right = num;
            while (numset.find(left) != numset.end())
            {
                numset.erase(left--);
            }
            while (numset.find(++right) != numset.end())
            {
                numset.erase(right);
            }
            longest = max(longest, right - left - 1);
        }
        return longest;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    cout << s.longestConsecutive(nums);
    return 0;
}