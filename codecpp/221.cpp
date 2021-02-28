#include "header.h"

#define rep(i, f, t, s) for (int i = f; i <= (int)t; i += s)
#define repd(i, f, t, s) for (int i = f; i >= (int)t; i -= s)
#define mk(a, b) make_pair(a, b)
#define sqr(a) ((a) * (a))
template <class Ty1, class Ty2>
inline const pair<Ty1, Ty2> operator+(const pair<Ty1, Ty2> &p1, const pair<Ty1, Ty2> &p2)
{
    return mk(p1.first + p2.first, p1.second + p2.second);
}
template <class Ty1, class Ty2>
inline const pair<Ty1, Ty2> operator-(const pair<Ty1, Ty2> &p1, const pair<Ty1, Ty2> &p2)
{
    return mk(p1.first - p2.first, p1.second - p2.second);
}
template <class Ty1, class Ty2>
bool inner(pair<Ty1, Ty2> pos, pair<Ty1, Ty2> leftTop, pair<Ty1, Ty2> rightBottom)
{
    if (pos.first >= leftTop.first && pos.second >= leftTop.second)
    {
        if (pos.first < rightBottom.first && pos.second < rightBottom.second)
        {
            return true;
        }
    }
    return false;
}

// Solution Here
class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        vector<vector<vector<bool>>> dp(2, vector<vector<bool>>(matrix.size(), vector<bool>(matrix[0].size())));
        int maxSquare = 0, minlen = min(matrix.size(), matrix[0].size()), pre;
        for (int i = 1; i <= minlen; ++i) // 用int表示可以优化掉这层循环
        {
            pre = (i - 1) & 1;
            for (int j = 0; j < matrix.size(); ++j)
            {
                for (int k = 0; k < matrix[j].size(); ++k)
                {
                    dp[i & 1][j][k] = false;
                    if (matrix[j][k] == '1')
                    {
                        if (i == 1)
                            dp[i & 1][j][k] = true;
                        else if (j > 0 && k > 0 && dp[pre][j - 1][k] && dp[pre][j][k - 1] && dp[pre][j - 1][k - 1])
                        {
                            maxSquare = max(maxSquare, i);
                            dp[i & 1][j][k] = true;
                        }
                    }
                }
            }
        }
        return maxSquare;
    }
};

int main()
{
    return 0;
}