#include "header.h"

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstCol=false,firstRow=false;
        for (int i=0;i<matrix.size();++i){
            for (int j=0;j<matrix[0].size();++j){
                if (matrix[i][j]==0){
                    firstRow=(i==0)||firstRow;
                    firstCol=(j==0)||firstCol;
                    if (i!=0 && j!=0){
                        matrix[0][j]=0;
                        matrix[i][0]=0;
                    }
                }
            }
        }
        for (int i=1;i<matrix.size();++i){
            for (int j=1;j<matrix[0].size();++j){
                matrix[i][j]=!(matrix[i][0]&&matrix[0][j])?0:matrix[i][j];
            }
        }
        if (firstCol){
            for (int i=0;i<matrix.size();++i){
                matrix[i][0]=0;
            }
        }
        if (firstRow){
            for (int i=0;i<matrix[0].size();++i){
                matrix[0][i]=0;
            }
        }
    }
};

int main(){
    vector<vector<int>> matrix={
        {0,1,2,0},{3,4,0,2},{1,3,1,5}
    };
    Solution s;
    s.setZeroes(matrix);
    fmt::printArray2(matrix);
    return 0;
}