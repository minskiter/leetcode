#include "header.h"

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        if (matrix.size()==0) return vector<vector<int>>();
        vector<vector<int>> transMatrix(matrix[0].size(),vector<int>(matrix.size()));
        for (int i=0;i<matrix.size();++i){
            for (int j=0;j<matrix[i].size();++j){
                transMatrix[j][i]=matrix[i][j];
            }
        }
        return transMatrix;
    }
};

int main(){
    return 0;
}