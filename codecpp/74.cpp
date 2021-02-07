#include "header.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowLen = matrix[0].size(),l=0,r=matrix.size()*rowLen-1,mid;
        while (l<=r){
            mid=(l+r)>>1;
            if (matrix[mid/rowLen][mid%rowLen]<target){
                l=mid+1;
            }else if (matrix[mid/rowLen][mid%rowLen]==target){
                return true;
            }else{
                r=mid-1;
            }
        }
        return false;
    }
};

int main(){
    vector<vector<int>> matrix = {
        {1}
    };
    Solution s;
    cout << s.searchMatrix(matrix,2);
    return 0;
}