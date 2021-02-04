#include "header.h"

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i;
        for (i=nums.size()-1;i>=1;--i){
            if (nums[i]>nums[i-1]){
                int tempIndex = i;
                for (int j =i;j<nums.size();++j){
                    if (nums[j]>nums[i-1] && nums[j]<nums[tempIndex]){
                        tempIndex=j;
                    };
                }
                cout << tempIndex << endl;
                swap(nums[tempIndex],nums[i-1]);
                break;
            }
        }
        sort(nums.begin()+i,nums.end());
    }
};

int main(){
    vector<int> test = {1,3,2,4,5};
    Solution s;
    s.nextPermutation(test);
    fmt::printArray(test);
    return 0;
}