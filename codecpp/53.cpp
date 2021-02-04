#include "header.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxAns=nums[0];
        int ans=nums[0];
        for (int i=1;i<nums.size();++i){
            if (ans<0) ans=0;
            ans+=nums[i];
            maxAns=max(ans,maxAns);
        }
        return maxAns;
    }
};

int main(){
    Solution s;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << s.maxSubArray(nums);
    return 0;
}