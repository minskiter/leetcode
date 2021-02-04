#include "header.h"

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int ans = INT_MAX / 2;
        for (int i = 0; i < nums.size(); ++i)
        {
            int l = i + 1, r = nums.size() - 1;
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                sum > target ? r-- : l++;
                if (abs(sum - target) < abs(ans - target))
                    ans = sum;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> temp = {-1, 2, 1000, -4};
    cout << s.threeSumClosest(temp, 1);
    return 0;
}