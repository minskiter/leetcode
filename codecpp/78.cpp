#include "header.h"

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ansV;
        vector<int> ans;
        ansV.push_back(ans);
        for (int i=0;i<nums.size();++i){
            search(1,nums,ansV,ans,i+1,nums.size());
        }
        return ansV;
    }  
private:
    void search(int deepth,vector<int> & nums,vector<vector<int>> & ansV,vector<int> & ans,int k,int n){
        if (ans.size()==k){
            ansV.push_back(ans);
            return;
        }
        if (n-deepth+1<k-(int)ans.size()){
            return;
        }
        for (int i=deepth;i<=n;++i){
            ans.push_back(nums[i-1]);
            search(i+1,nums,ansV,ans,k,n);
            ans.pop_back();
        }
    }
}; 

int main(){
    Solution s;
    vector<int> nums = {0,1,2,3,4,5,6,7,8,9};
    fmt::printArray2(s.subsets(nums));
    return 0;
}