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
    int nthSuperUglyNumber(int n, vector<int> &primes)
    {
        vector<int> nums{1};
        vector<int> ptr(primes.size());
        for (int i = 0; i < n; ++i)
        {
            long long mininum = (long long)nums[ptr[0]] * primes[0];
            for (int j = 1; j < primes.size(); ++j)
                mininum = min(mininum, (long long)nums[ptr[j]] * primes[j]);
            for (int j = 0; j < primes.size(); ++j)
                if ((long long)nums[ptr[j]] * primes[j] == mininum)
                    ++ptr[j];
            nums.emplace_back(mininum);
        }
        return nums[n - 1];
    }
};

int main()
{
    return 0;
}