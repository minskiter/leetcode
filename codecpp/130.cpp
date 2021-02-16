#include "header.h"

class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        if (board.size() == 0)
            return;
        vector<vector<bool>> vis(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (isInnerO(board, vis, i, j))
                {
                    fillX(board, i, j);
                }
            }
        }
    }

private:
    vector<vector<int>> direction = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    bool isInnerO(vector<vector<char>> &board, vector<vector<bool>> &vis, int &x, int &y)
    {
        if (board[x][y] == 'X' || vis[x][y])
            return false;
        queue<pair<int, int>> q;
        q.push(make_pair(x, y));
        vis[x][y] = true;
        pair<int, int> front;
        bool ans = true;
        while (!q.empty())
        {
            front = q.front();
            q.pop();
            for (int i = 0; i < direction.size(); ++i)
            {
                int nxtX = front.first + direction[i][0], nxtY = front.second + direction[i][1];
                if (nxtX < 0 || nxtY < 0 || nxtX >= board.size() || nxtY >= board[0].size())
                {
                    ans = false;
                    continue;
                }
                if (!vis[nxtX][nxtY] && board[nxtX][nxtY] == 'O')
                {
                    vis[nxtX][nxtY] = true;
                    q.push(make_pair(nxtX, nxtY));
                }
            }
        }
        return ans;
    }
    void fillX(vector<vector<char>> &board, int &x, int &y)
    {
        if (board[x][y] == 'X')
            return;
        queue<pair<int, int>> q;
        q.push(make_pair(x, y));
        board[x][y] = 'X';
        pair<int, int> front;
        while (!q.empty())
        {
            front = q.front();
            q.pop();
            for (int i = 0; i < direction.size(); ++i)
            {
                int nxtX = front.first + direction[i][0], nxtY = front.second + direction[i][1];
                if (nxtX < 0 || nxtY < 0 || nxtX >= board.size() || nxtY >= board[0].size())
                    continue;
                if (board[nxtX][nxtY] == 'O')
                {
                    board[nxtX][nxtY] = 'X';
                    q.push(make_pair(nxtX, nxtY));
                }
            }
        }
    }
};

int main()
{
    vector<vector<char>> graph = {
        {'X', 'O', 'X', 'O', 'X', 'O'},
        {'O', 'X', 'O', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'O', 'X', 'O'},
        {'O', 'X', 'O', 'X', 'O', 'X'}};
    Solution s;
    s.solve(graph);
    fmt::printArray2(graph);
    return 0;
}