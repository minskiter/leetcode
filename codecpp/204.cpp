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
    int countPrimes(int n)
    {
        vector<bool> isPrime(n + 1, true);
        vector<int> primes;
        int cnt;
        for (int i = 2; i <= n; ++i)
        {
            if (isPrime[i])
            {
                primes.push_back(i);
            }
            for (int j = 0; j < primes.size(); ++j)
            {
                if (i * primes[j] >= n)
                    break;
                isPrime[primes[j] * i] = false;
                if (i % primes[j] == 0)
                    break;
            }
        }
        return primes.size();
    }
};

int main()
{
    return 0;
}