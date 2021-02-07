#include "header.h"

class Solution
{
public:
    int mySqrt(int x)
    {
        int l = 0, r = 46340, mid;
        while (l <= r)
        {
            mid = (l + r) >> 1;
            if (mid * mid < x)
            {
                l = mid + 1;
            }
            else if (mid * mid == x)
            {
                return mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        return r;
    }
};

int main()
{
    Solution s;
    cout << s.mySqrt(INT_MAX);
    return 0;
}