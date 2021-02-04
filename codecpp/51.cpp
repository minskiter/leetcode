#include "header.h"

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        int v = (1 << n) - 1, d = (1 << (n * 2 - 1)) - 1, a = d;
        // initialization horizen vertical diagonal anti-diagonal
        vector<vector<string>> ansV;
        vector<string> ans;
        search(ansV, ans, n, 0, v, d, a);
        return ansV;
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
    void search(vector<vector<string>> &ansV, vector<string> &ans, int n, int deepth, int v, int d, int a)
    {
        if (deepth >= n)
        {
            ansV.push_back(ans);
            return;
        }
        int left = v;
        while (left)
        {
            int bit = left & (-left);
            int vn = getBit(bit) - 1;
            if ((d & (1 << (deepth + vn))) && (a & (1 << (n - 1 - deepth + vn))))
            {
                string temp = "";
                for (int i = 0; i < n; ++i)
                {
                    if (i == vn)
                    {
                        temp = temp + "Q";
                    }
                    else
                    {
                        temp = temp + ".";
                    }
                }
                ans.push_back(temp);
                search(ansV, ans, n, deepth + 1, v - bit, d - (1 << (deepth + vn)), a - (1 << (n - 1 - deepth + vn)));
                ans.pop_back();
            }
            left -= bit;
        }
    }
};

int main()
{
    Solution s;
    fmt::printArray2(s.solveNQueens(9));
    return 0;
}