#include "header.h"

class Solution
{
public:
    int totalNQueens(int n)
    {
        int v = (1 << n) - 1, d = (1 << (n * 2 - 1)) - 1, a = d;
        // initialization horizen vertical diagonal anti-diagonal
        int ans=0;
        search(ans, n, 0, v, d, a);
        return ans;
    }

private:
    int getBit(int bit)
    {
        int ans = 0;
        while (bit)
        {
            ans++;
            bit >>= 1;
        }
        return ans;
    }
    void search(int & ans, int n, int deepth, int v, int d, int a)
    {
        if (deepth >= n)
        {
            ans++;
            return;
        }
        int left = v;
        while (left)
        {
            int bit = left & (-left);
            int vn = getBit(bit) - 1;
            if ((d & (1 << (deepth + vn))) && (a & (1 << (n - 1 - deepth + vn))))
            {
                search(ans, n, deepth + 1, v - bit, d - (1 << (deepth + vn)), a - (1 << (n - 1 - deepth + vn)));
            }
            left -= bit;
        }
    }
};

int main()
{
    Solution s;
    cout << s.totalNQueens(9);
    return 0;
}