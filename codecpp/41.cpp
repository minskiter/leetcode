#include "header.h"

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i=0;i<nums.size();++i){
            if (nums[i]<=0 && nums[i]>nums.size()){
                nums[i]=-1;
            }else if (nums[i]==i+1){
                continue;
            }else{
                while (nums[i]>0 && nums[i]<=nums.size() && nums[nums[i]-1]!=nums[i]){
                    swap(nums[nums[i]-1],nums[i]);
                }
            }
        }
        for (int i=0;i<nums.size();++i){
            if (nums[i]!=i+1){
                return i+1;
            }
        }
        return nums.size()+1;
    }
};

int main(){
    Solution s;
    vector<int> nums={1,3,2000000,4,5};
    cout << s.firstMissingPositive(nums);
    return 0;
}