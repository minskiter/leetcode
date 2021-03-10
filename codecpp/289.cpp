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
    static vector<pair<int, int>> neighbors;
    void gameOfLife(vector<vector<int>> &board)
    {
        auto leftTop = mk(0, 0);
        auto rightBottom = mk((int)board.size(), (int)board[0].size());
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); ++j)
            {
                int f = board[i][j] > 0 ? 1 : -1;
                for (int k = 0; k < 4; ++k)
                {
                    auto nxt = mk(i, j) + neighbors[k];
                    if (inner(nxt, leftTop, rightBottom))
                    {
                        board[i][j] += board[nxt.first][nxt.second] > 0 ? 1 : -1;
                        board[nxt.first][nxt.second] += f;
                    }
                }
                if (board[i][j] < -3)
                    board[i][j] = 1;
                else if (board[i][j] <= 0)
                    board[i][j] = 0;
                else if (board[i][j] < 3 || board[i][j] > 4)
                    board[i][j] = 0;
                else
                    board[i][j] = 1;
            }
        }
    }
};

vector<pair<int, int>> Solution::neighbors = {{1, 0}, {1, -1}, {0, 1}, {1, 1}};

int main()
{

    return 0;
}