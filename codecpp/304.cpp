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

class NumMatrix
{
    vector<vector<int>> buffer;

public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        buffer.emplace_back(vector<int>(matrix[0].size() + 1, 0));
        for (int i = 0; i < matrix.size(); ++i)
        {
            buffer.emplace_back(vector<int>(1));
            for (int j = 0; j < matrix[i].size(); ++j)
            {
                buffer[i + 1].emplace_back(matrix[i][j]);
                buffer[i + 1][j + 1] += buffer[i + 1][j] + buffer[i][j + 1] - buffer[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return buffer[row2 + 1][col2 + 1] - buffer[row2 + 1][col1] - buffer[row1][col2 + 1] + buffer[row1][col1];
    }
};

int main()
{
    vector<vector<int>> matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}};
    NumMatrix s(matrix);
    cout << s.sumRegion(2, 1, 4, 3) << endl;
    return 0;
}