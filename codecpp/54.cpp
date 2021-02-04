#include "header.h"

class Solution
{
private:
    vector<vector<int>> forward = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}};

public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int f = 0;
        int len = matrix.size() * matrix[0].size();
        int x = 0, y = -1;
        int cycle = 1;
        int path = matrix[0].size();
        vector<int> ans = {};
        for (int i = 0; i < len; ++i)
        {
            if (path == 0)
            {
                f = (f + 1) % 4;
                cycle++;
                if (f & 1)
                {
                    path = matrix.size() - (cycle / 2);
                }
                else
                {
                    path = matrix[0].size() - (cycle / 2);
                }
            }
            x += forward[f][0], y += forward[f][1];
            ans.push_back(matrix[x][y]);
            path--;
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20}};
    Solution s;
    fmt::printArray(s.spiralOrder(matrix));
    return 0;
}