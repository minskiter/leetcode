#include "header.h"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1,mid;
        while (l<=r){
            mid = (l+r)>>1;
            if (nums[mid]>target){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        int maxium = mid;
        while (maxium && nums[maxium]>target){
            maxium--;
        }
        l=0,r=nums.size()-1,mid;
        while (l<=r){
            mid = (l+r)>>1;
            if (nums[mid]>=target){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        int minium=mid;
        while (minium<nums.size() && nums[minium]<target){
            minium++;
        }
        if (nums.size()==0 || minium>maxium || nums[minium]!=target){
            maxium=minium=-1;
        }
        vector<int> ans={minium,maxium};
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> test = {1};
    fmt::printArray(s.searchRange(test,0));
    return 0;
}