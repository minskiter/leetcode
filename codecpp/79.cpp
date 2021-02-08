#include "header.h"

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] == word[0])
                {
                    visited[i][j] = true;
                    if (search(i, j, board, visited, word, 1))
                    {
                        return true;
                    }
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }

private:
    vector<vector<int>> forward = {
        {0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    bool search(int x, int y, vector<vector<char>> &board, vector<vector<bool>> &visited, string &word, int deepth)
    {
        if (deepth >= word.size())
        {
            return true;
        }
        for (int i = 0; i < 4; ++i)
        {
            int nxtX = x + forward[i][0], nxtY = y + forward[i][1];
            if (nxtX >= 0 && nxtX < board.size() && nxtY >= 0 && nxtY < board[0].size())
            {
                if (!visited[nxtX][nxtY] && board[nxtX][nxtY] == word[deepth])
                {
                    visited[nxtX][nxtY] = true;
                    if (search(nxtX, nxtY, board, visited, word, deepth + 1))
                    {
                        return true;
                    }
                    visited[nxtX][nxtY] = false;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    cout << s.exist(board,"ABCB");
    return 0;
}