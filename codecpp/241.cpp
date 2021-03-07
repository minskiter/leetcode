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
    vector<int> diffWaysToCompute(string input)
    {
        vector<int> nums;
        vector<char> operators;
        int num = 0;
        for (int i = 0; i < input.size(); ++i)
        {
            if (input[i] >= '0' && input[i] <= '9')
                num = num * 10 + (input[i] - '0');
            else if (input[i] == '-' || input[i] == '+' || input[i] == '*')
            {
                operators.emplace_back(input[i]);
                nums.emplace_back(num);
                num = 0;
            }
        }
        if (nums.size() == 0)
            return vector<int>();
        nums.emplace_back(num);
        if (operators.size() == 0)
            return nums;
        vector<vector<vector<int>>> s(nums.size(), vector<vector<int>>(nums.size(), vector<int>()));
        for (int step = 1; step <= nums.size(); ++step)
        {
            for (int l = 0; l + step - 1 < nums.size(); ++l)
            {
                int r = l + step - 1;
                if (l == r)
                {
                    s[l][r].emplace_back(nums[l]);
                }
                else
                {
                    for (int mid = l; mid < r; ++mid)
                    {
                        for (int i = 0; i < s[l][mid].size(); ++i)
                        {
                            for (int j = 0; j < s[mid + 1][r].size(); ++j)
                            {
                                switch (operators[mid])
                                {
                                case '-':
                                    s[l][r].emplace_back(s[l][mid][i] - s[mid + 1][r][j]);
                                    break;
                                case '+':
                                    s[l][r].emplace_back(s[l][mid][i] + s[mid + 1][r][j]);
                                    break;
                                case '*':
                                    s[l][r].emplace_back(s[l][mid][i] * s[mid + 1][r][j]);
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        return s[0][nums.size() - 1];
    }
};

int main()
{
    cout << Solution().diffWaysToCompute("2*3-4*5");
    return 0;
}