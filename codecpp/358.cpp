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
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
    {
        for (int row = 0; row < matrix.size(); row++)
        {
            for (int col = 0; col < matrix[row].size(); ++col)
            {
                if (col != 0)
                {
                    matrix[row][col] += matrix[row][col - 1];
                    if (row != 0)
                    {
                        matrix[row][col] += matrix[row - 1][col];
                        matrix[row][col] -= matrix[row - 1][col - 1];
                    }
                }
                else if (row != 0)
                    matrix[row][col] += matrix[row - 1][col];
            }
        }
        int ans = INT_MIN;
        if (matrix.size() < matrix[0].size())
        {
            for (int l = 0; l < matrix.size(); ++l)
            {
                for (int r = l; r < matrix.size(); ++r)
                {
                    for (int col = 0; col < matrix[0].size(); ++col)
                    {
                        set<int> sums;
                        int sum = matrix[r][col] - (l == 0 ? 0 : matrix[l - 1][col]);
                        auto itor = sums.lower_bound(sum - k);
                        if (itor == sums.end())
                        {
                            if (sum <= k)
                                ans = max(ans, sum);
                        }
                        else
                        {
                            ans = max(ans, sum - *itor);
                        }
                        sums.emplace(sum);
                    }
                }
            }
        }
        else
        {
            for (int l = 0; l < matrix[0].size(); ++l)
            {
                for (int r = l; r < matrix[0].size(); ++r)
                {
                    for (int row = 0; row < matrix.size(); ++row)
                    {
                        set<int> sums;
                        int sum = matrix[row][r] - (l == 0 ? 0 : matrix[row][l - 1]);
                        auto itor = sums.lower_bound(sum - k);
                        if (itor == sums.end())
                        {
                            if (sum <= k)
                                ans = max(ans, sum);
                        }
                        else
                        {
                            ans = max(ans, sum - *itor);
                        }
                        sums.emplace(sum);
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 0, 1}, {0, -2, 3}};
    cout << Solution().maxSumSubmatrix(matrix, 2);
    return 0;
}