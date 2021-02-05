#include "header.h"

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        vector<vector<int>> mins(2, vector<int>(grid[0].size(), INT_MAX / 2));
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (i == 0 && j == 0)
                    mins[i][j] = grid[i][j];
                else
                {
                    mins[i & 1][j] = INT_MAX / 2;
                    if (i > 0)
                        mins[i & 1][j] = min(mins[i & 1][j], mins[(i - 1) & 1][j] + grid[i][j]);
                    if (j > 0)
                    {
                        mins[i & 1][j] = min(mins[i & 1][j], mins[i & 1][j - 1] + grid[i][j]);
                    }
                }
            }
        }
        return mins[(grid.size()-1)&1][grid[0].size()-1];
    }
};

int main()
{
    vector<vector<int>> grid{
        {1,2,3},{4,5,6}
    };
    Solution s;
    cout << s.minPathSum(grid) << endl;
    return 0;
}