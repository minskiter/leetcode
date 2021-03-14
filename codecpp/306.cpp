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
    bool isAdditiveNumber(string num)
    {
        long long a = 0, b = 0;
        for (int i = 0; i < min<int>(num.size() - 2, 14); ++i)
        {
            a = a * 10 + (num[i] - '0');
            b = 0;
            for (int j = i + 1; j < min<int>(num.size() - 1, i + 14); ++j)
            {
                b = b * 10 + (num[j] - '0');
                if (search(num, j + 1, a, b))
                {
                    return true;
                }
                if (b == 0)
                    break;
            }
            if (a == 0)
                break;
        }
        return false;
    }

private:
    bool search(string &num, int deepth, long long a, long long b)
    {
        if (num.size() == deepth)
        {
            return true;
        }
        long long sum = 0;
        for (int i = deepth; i < min<int>(num.size(), deepth + 14); ++i)
        {
            sum = sum * 10 + (num[i] - '0');
            if (sum == a + b)
            {
                return search(num, i + 1, b, sum);
                break;
            }
            if (sum == 0)
                break;
        }
        return false;
    }
};

int main()
{
    cout << Solution().isAdditiveNumber("199100199");
    return 0;
}