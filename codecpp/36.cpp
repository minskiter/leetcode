#include "header.h"

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); ++i)
        {
            int flag = 0;
            for (int j = 0; j < board.size(); ++j)
            {
                if (board[i][j] == '.')
                    continue;
                if (flag & (1 << (board[i][j] - '1')))
                {
                    return false;
                }
                flag += (1 << (board[i][j]) - '1');
            }
        }
        for (int i = 0; i < board.size(); ++i)
        {
            int flag = 0;
            for (int j = 0; j < board.size(); ++j)
            {
                if (board[j][i] == '.')
                    continue;
                if (flag & (1 << (board[j][i] - '1')))
                {
                    return false;
                }
                flag += (1 << (board[j][i]) - '1');
            }
        }
        for (int i = 0; i < board.size(); i += 3)
        {
            for (int j = 0; j < board.size(); j += 3)
            {
                int flag = 0;
                for (int k = i; k < i + 3; ++k)
                {
                    for (int l = j; l < j + 3; ++l)
                    {
                        if (board[k][l] == '.')
                            continue;
                        if (flag & (1 << (board[k][l] - '1')))
                        {
                            return false;
                        }
                        flag += (1 << (board[k][l] - '1'));
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    vector<vector<char>> test = {
        {'9', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    Solution s;
    cout << s.isValidSudoku(test);
    return 0;
}