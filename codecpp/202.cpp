#include "header.h"

#define rep(i, f, t, s) for (int i = f; i <= t; i += s)
#define repd(i, f, t, s) for (int i = f; i >= t; i -= s)
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

// Solution Here
class Solution
{
public:
    static unordered_map<int, bool> cache;
    bool isHappy(int n)
    {
        if (n == 1)
            return true;
        int sum = 0;
        while (n)
        {
            sum += sqr(n % 10);
            n /= 10;
        }
        if (cache.find(sum) != cache.end())
            return cache[sum];
        cache[sum] = false;
        return (cache[sum] = isHappy(sum));
    }
};

unordered_map<int, bool> Solution::cache;

int main()
{
    cout << Solution().isHappy(2);
    return 0;
}