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

vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

// Solution Here
class Solution
{
public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        auto leftTop = mk(0, 0), rightBottom = mk((int)matrix.size(), (int)matrix[0].size());
        vector<vector<int>> deg(matrix.size(), vector<int>(matrix[0].size())), dp(matrix.size(), vector<int>(matrix[0].size(), 1));
        for (int i = 0; i < matrix.size(); ++i)
            for (int j = 0; j < matrix[i].size(); ++j)
                for (int k = 0; k < 4; ++k)
                {
                    auto nxt = mk(i, j) + dir[k];
                    if (inner(nxt, leftTop, rightBottom) && matrix[nxt.first][nxt.second] > matrix[i][j])
                        deg[nxt.first][nxt.second]++;
                }
        queue<pair<int, int>> q;
        for (int i = 0; i < matrix.size(); ++i)
            for (int j = 0; j < matrix[i].size(); ++j)
                if (deg[i][j] == 0)
                    q.emplace(mk(i, j));
        int ans = 1;
        while (!q.empty())
        {
            auto front = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i)
            {
                auto nxt = front + dir[i];
                if (inner(nxt, leftTop, rightBottom) && matrix[nxt.first][nxt.second] > matrix[front.first][front.second])
                {
                    --deg[nxt.first][nxt.second];
                    dp[nxt.first][nxt.second] = max(dp[nxt.first][nxt.second], dp[front.first][front.second] + 1);
                    ans = max(ans, dp[nxt.first][nxt.second]);
                    if (deg[nxt.first][nxt.second] == 0)
                        q.emplace(nxt);
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> matrix = {{3,4,5},{3,2,6},{2,2,1}};
    cout << Solution().longestIncreasingPath(matrix);
    return 0;
}