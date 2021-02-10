// 待优化 
#include "header.h"

#define rep(i, f, t) for (int i = f; i <= t; ++i)
#define repd(i, f, t) for (int i = f; i >= t; --i)
#define ll long long
class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.size() == 0)
            return 0;
        if (matrix[0].size() == 0)
            return 0;
        vector<vector<vector<int>>> sum(2, vector<vector<int>>(matrix[0].size(), vector<int>(matrix[0].size())));
        int ans = 0;
        bool flag;
        rep(i, 0, matrix.size() - 1)
        {
            rep(j, 0, matrix[0].size() - 1)
            {
                flag = false;
                repd(k, j, 0)
                {
                    flag = (matrix[i][k] == '0') || flag;
                    sum[i & 1][k][j] = flag ? 0 : i > 0 ? sum[(i - 1) & 1][k][j] + j - k + 1 : j - k + 1;
                    ans = max(ans, sum[i & 1][k][j]);
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    cout << s.maximalRectangle(matrix);
    return 0;
}