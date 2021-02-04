#include "header.h"

class Solution
{
private:
    vector<vector<int>> forward = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}};

public:
    vector<vector<int>> generateMatrix(int n)
    {
        int f = 0;
        int len = n*n;
        int x = 0, y = -1;
        int cycle = 1;
        int path = n;
        vector<vector<int>> ans(n,vector<int>(n));
        for (int i = 0; i < len; ++i)
        {
            if (path == 0)
            {
                f = (f + 1) % 4;
                cycle++;
                if (f & 1)
                {
                    path = n - (cycle / 2);
                }
                else
                {
                    path = n - (cycle / 2);
                }
            }
            x += forward[f][0], y += forward[f][1];
            ans[x][y]=i+1;
            path--;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    fmt::printArray2(s.generateMatrix(5));
    return 0;
}