#include "header.h"

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i=0;i<matrix.size()/2;++i){
            for (int j=0;j<matrix.size();++j){
                swap(matrix[i][j],matrix[matrix.size()-i-1][j]);
            }
        }
        for (int i=0;i<matrix.size();++i){
            for (int j=0;j<i;++j){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};

int main(){
    vector<vector<int>> matrix={
        {5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}
    };
    Solution s;
    s.rotate(matrix);
    fmt::printArray2(matrix);
    return 0;
}