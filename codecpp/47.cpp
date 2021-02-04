#include "header.h"

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ansV;
        vector<int> ans;
        search(ansV,ans,nums,0,(1<<nums.size())-1);
        return ansV;
    }
private:
    void search(vector<vector<int>> & ansV,vector<int> &ans,vector<int> &nums,int deepth,int visited){
        if (deepth==nums.size()){
            ansV.push_back(ans);
        }
        for (int i=0;i<nums.size();++i){
            if ((1<<i)&visited){
                if (i>0 && nums[i]==nums[i-1] && !(visited&(1<<(i-1)))){
                    continue;
                }
                ans.push_back(nums[i]);
                search(ansV,ans,nums,deepth+1,visited-(1<<i));
                ans.pop_back();
            }
        }
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3,1};
    fmt::printArray2(s.permuteUnique(nums));
    return 0;
}