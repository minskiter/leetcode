#include "header.h"

#define rep(i, f, t, s) for (int i = f; i <= t; i += s)
#define repd(i, f, t, s) for (int i = f; i >= t; i -= s)

class Solution
{
private:
public:
    int majorityElement(vector<int> &nums)
    {
        if (nums.size() == 0)
            return -1;
        int cnt = 1;
        int pre = nums[0];
        rep(i, 1, nums.size() - 1, 1)
        {
            if (nums[i] == pre)
            {
                cnt++;
            }
            else
            {
                --cnt;
                if (cnt < 0)
                {
                    cnt = 1;
                    pre = nums[i];
                }
            }
        }
        cnt =0;
        rep(i,0,nums.size()-1,1){
            if (nums[i]==pre) ++cnt;
        }
        return cnt>nums.size()/2?pre:-1;
    }
};

int main()
{
    Solution s;
    return 0;
}