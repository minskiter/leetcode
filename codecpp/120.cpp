#include "header.h"

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int ans=triangle.size()==1?triangle[0][0]:INT_MAX;
        for (int i=1;i<triangle.size();++i){
            for (int j=0;j<triangle[i].size();++j){
                if (j==0){
                    triangle[i][j]+=triangle[i-1][j];
                }else if (j==triangle[i].size()-1){
                    triangle[i][j]+=triangle[i-1][j-1];
                }else{
                    triangle[i][j]+=min(triangle[i-1][j],triangle[i-1][j-1]);
                }
                if (i==triangle.size()-1){
                    ans=min(ans,triangle[i][j]);
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>> triangle={
        {2},{3,4},{6,5,7},{4,1,8,3}
    };
    cout << s.minimumTotal(triangle);
    return 0;
}