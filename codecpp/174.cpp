#include "header.h"

class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        int l = 0, r = INT_MAX, mid;
        while (l < r)
        {
            mid = l + (r - l) / 2;
            if (isLive(dungeon, mid))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }

private:
    bool isLive(vector<vector<int>> dungeon, int health)
    {
        dungeon[0][0] += health;
        for (int i = 0; i < dungeon.size(); ++i)
        {
            for (int j = 0; j < dungeon[i].size(); ++j)
            {
                if (i == 0)
                {
                    if (j > 0)
                    {
                        if (dungeon[i][j - 1] <= 0)
                            dungeon[i][j] = 0;
                        else
                            dungeon[i][j] += dungeon[i][j - 1];
                    }
                }
                else
                {
                    if (j == 0)
                    {
                        if (dungeon[i - 1][j] <= 0)
                            dungeon[i][j] = 0;
                        else
                            dungeon[i][j] += dungeon[i - 1][j];
                    }
                    else
                    {
                        int maxinum = max(dungeon[i - 1][j], dungeon[i][j - 1]);
                        if (maxinum <= 0)
                            dungeon[i][j] = 0;
                        else
                            dungeon[i][j] += maxinum;
                    }
                }
            }
        }
        return dungeon[dungeon.size() - 1][dungeon[0].size() - 1] > 0;
    }
};

int main()
{
    vector<vector<int>> dungeon{{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    cout << Solution().calculateMinimumHP(dungeon);
    return 0;
}