#include "header.h"

class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        vector<int> vertical(board.size(), (1 << board.size()) - 1), horizon(board.size(), (1 << board.size()) - 1), subbox(board.size(), (1 << board.size()) - 1);
        vector<int> poses;
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board.size(); ++j)
            {
                if (board[i][j] != '.')
                {
                    vertical[j] -= (1 << (board[i][j] - '1'));
                    horizon[i] -= (1 << (board[i][j] - '1'));
                    subbox[i / 3 * 3 + j / 3] -= (1 << (board[i][j] - '1'));
                }
                else
                {
                    poses.push_back(i * board.size() + j);
                }
            }
        }
        search(board, 0, poses, vertical, horizon, subbox);
    }

private:
    int getNumber(int bit)
    {
        int ans = 0;
        while (bit > 0)
        {
            bit >>= 1;
            ans++;
        }
        return ans;
    }
    bool search(vector<vector<char>> &board, int deepth, vector<int> &poses, vector<int> &vertical, vector<int> &horizon, vector<int> &subbox)
    {
        if (deepth >= poses.size())
        {
            return true;
        }
        int h = poses[deepth] / board.size(), v = poses[deepth] % board.size();
        int left = horizon[h] & vertical[v] & subbox[h / 3 * 3 + v / 3];
        while (left>0)
        {
            int bit = left & (-left);
            int num = getNumber(bit);
            board[h][v] = num + '0';
            vertical[v] -= bit;
            horizon[h] -= bit;
            subbox[h / 3 * 3 + v / 3] -= bit;
            if (search(board, deepth + 1, poses, vertical, horizon, subbox))
            {
                return true;
            }
            vertical[v] += bit;
            horizon[h] += bit;
            subbox[h / 3 * 3 + v / 3] += bit;
            left -= bit;
        }
        return false;
    };
};

int main()
{
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    Solution s;
    s.solveSudoku(board);
    fmt::printArray2(board);
    return 0;
}