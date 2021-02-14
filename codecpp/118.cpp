#include "header.h"

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if (numRows==0) return ans;
        ans.push_back(vector<int>(1,1));
        for (int i=1;i<numRows;++i){
            ans.push_back(vector<int>());
            for (int j=0;j<i;++j){
                if (j==0){
                    ans[i].push_back(1);
                }else{
                    ans[i].push_back(ans[i-1][j-1]+ans[i-1][j]);
                }
            }
            ans[i].push_back(1);
        }
        return ans;
    }
};

int main(){
    Solution s;
    fmt::printArray2(s.generate(5));
    return 0;
}