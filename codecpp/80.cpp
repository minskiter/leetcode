#include "header.h"

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int len = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (len > 1 && nums[i] == nums[len-1] && nums[len-1] == nums[len-2])
            {
                continue;
            }
            nums[len++] = nums[i];
        }
        return len;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {0,0,1,1,1,1,2,3,3};
    int len =s.removeDuplicates(nums);
    for (int i=0;i<len;++i){
        cout << nums[i];
        if (i!=len-1){
            cout << ' ';
        }
    }
    return 0;
}