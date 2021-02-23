#include "header.h"

class Solution
{
public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {
        for (int i = 0; i < matrix.size(); ++i)
            for (int l = 1; l < matrix[i].size(); ++l)
                matrix[i][l] += matrix[i][l - 1];
        int cnt=0;
        for (int l = 0; l < matrix[0].size(); ++l)
        {
            for (int r = l; r < matrix[0].size(); ++r)
            {
                for (int row = 0; row < matrix.size(); ++row)
                {
                    int sum = 0;
                    for (int end = row; end < matrix.size(); ++end)
                    {
                        sum+=matrix[end][r]-(l==0?0:matrix[end][l-1]);
                        if (sum==target) cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};

int main()
{
    return 0;
}