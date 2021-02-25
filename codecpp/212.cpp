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
    vector<pair<int, int>> direction = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
    bool dfs(vector<string> &ans, pair<int, int> &pos, int deepth, unordered_set<short> &vis, vector<vector<char>> &board, string &word)
    {
        if (deepth == word.size() - 1)
        {
            ans.emplace_back(word);
            return true;
        }
        rep(d, 0, 3, 1)
        {
            auto nxt = pos + direction[d];
            if (inner<int, int>(nxt, mk(0, 0), mk(board.size(), board[0].size())))
            {
                if (vis.find(nxt.first * 13 + nxt.second) == vis.end() && board[nxt.first][nxt.second] == word[deepth + 1])
                {
                    vis.emplace(nxt.first * 13 + nxt.second);
                    if (dfs(ans, nxt, deepth + 1, vis, board, word))
                    {
                        return true;
                    }
                    vis.erase(nxt.first * 13 + nxt.second);
                }
            }
        }
        return false;
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        vector<string> ans;
        rep(i, 0, words.size() - 1, 1)
        {
            bool find = false;
            rep(row, 0, board.size() - 1, 1)
            {
                if (find)
                    break;
                rep(col, 0, board[row].size() - 1, 1)
                {
                    if (find)
                        break;
                    if (board[row][col] == words[i][0])
                    {

                        unordered_set<short> vis;
                        vis.emplace(row * 13 + col);
                        auto pos = mk(row, col);
                        if (dfs(ans, pos, 0, vis, board, words[i]))
                        {
                            find = true;
                            break;
                        }
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<char>> board = {{'a', 'b', 'c'}, {'a', 'e', 'd'}, {'a', 'f', 'g'}};
    vector<string> words = {"eaabcdgfa"};
    fmt::printArray(Solution().findWords(board, words));
    return 0;
}