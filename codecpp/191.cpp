#include "header.h"

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int cnt;
        while (n)
        {
            n -= (n & -n);
            ++cnt;
        }
        return cnt;
    }
};

int main()
{
    cout << Solution().hammingWeight(3) << endl;
    return 0;
}