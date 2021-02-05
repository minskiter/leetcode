#include "header.h"

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size()==0) return 0;
        vector<vector<int>> paths(2,vector<int>(obstacleGrid[0].size(),0));
        for (int i=0;i<obstacleGrid.size();++i){
            for (int j=0;j<obstacleGrid[0].size();++j){
                paths[i&1][j]=(i==0 && j==0 && obstacleGrid[i][j]==0);
                if (obstacleGrid[i][j]==0){
                    if (i>0) paths[i&1][j]+=paths[(i-1)&1][j];
                    if (j>0) paths[i&1][j]+=paths[i&1][j-1];
                }
            }
        }
        return paths[(obstacleGrid.size()-1)&1][obstacleGrid[0].size()-1];
    }
};

int main(){
    vector<vector<int>> obstacleGrid = {
        {0,0,0,0},
        {0,1,0,0},
        {0,0,0,0},
        {0,0,1,0},
        {0,0,0,0}
    };
    Solution s;
    cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}