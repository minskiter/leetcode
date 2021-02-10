#include "header.h"

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<bool> used(nums.size(),false);
        vector<vector<int>> ansV;
        vector<int> ans;
        search(ansV,ans,nums,0,used);
        return ansV;
    }
private:
    void search(vector<vector<int>> &ansV,vector<int> & ans,vector<int> & nums,int deepth,vector<bool> & used){
        if (deepth>=nums.size()){
            ansV.push_back(ans);
            return;
        }
        search(ansV,ans,nums,deepth+1,used);
        if (deepth>0 && nums[deepth]==nums[deepth-1] && !used[deepth-1])
            return;
        used[deepth]=true;
        ans.push_back(nums[deepth]);
        search(ansV,ans,nums,deepth+1,used);
        ans.pop_back();
        used[deepth]=false;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,2};
    fmt::printArray2(s.subsetsWithDup(nums));
    return 0;
}