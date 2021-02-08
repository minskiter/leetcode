#include "header.h"

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ansV;
        vector<int> ans;
        search(1,ansV,ans,k,n);
        return ansV;
    }
private:
    void search(int deepth,vector<vector<int>> & ansV,vector<int> & ans,int k,int n){
        if (ans.size()==k){
            ansV.push_back(ans);
            return;
        }
        if (n-deepth+1<k-(int)ans.size()){
            return;
        }
        for (int i=deepth;i<=n;++i){
            ans.push_back(i);
            search(i+1,ansV,ans,k,n);
            ans.pop_back();
        }
    }
};

int main(){
    Solution s;
    fmt::printArray2(s.combine(20,10));
    return 0;
}