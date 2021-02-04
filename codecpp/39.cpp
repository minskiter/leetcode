#include "header.h"

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ansV;
        vector<int> ans;
        search(ansV,ans,candidates,0,target);
        return ansV;
    }
private:
    void search(vector<vector<int>> &ansV,vector<int> &ans,vector<int>&candidates,int deepth,int target){
        if (target<=0){
            if (target==0){
                ansV.push_back(ans);
            }
            return ;
        }
        for (int i=deepth;i<candidates.size();++i){
            ans.push_back(candidates[i]);
            search(ansV,ans,candidates,i,target-candidates[i]);
            ans.pop_back();
        }
    }
};

int main(){
    Solution s;
    vector<int> test={10,1,2,7,6,1,5};
    fmt::printArray2(s.combinationSum(test,8));
    return 0;
}