#include "header.h"

class Solution
{
public:
    int trailingZeroes(int n)
    {
        int cnt = 0, i;
        while (n > 0)
        {
            int pcnt =0;
            for (i = 5; i <= n; i *= 5)
            {
                pcnt = pcnt * 5 + 1;
            }
            cnt+=pcnt;
            i /= 5;
            n -= i;
        }
        return cnt;
    }
};

int main()
{
    cout << Solution().trailingZeroes(50);
    return 0;
}