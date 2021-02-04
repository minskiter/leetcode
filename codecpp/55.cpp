#include "header.h"

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        for (int i=0;i<nums.size();++i){
            if (maxReach<i){
                return false;
            }
            maxReach=max(maxReach,i+nums[i]);
        }
        return true;
    }
};

int main(){
    Solution s;
    vector<int> nums = {3,2,1,0,4};
    cout << s.canJump(nums) << endl;
    return 0;
}