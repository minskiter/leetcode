#include "header.h"

class Solution
{
public:
    string convertToTitle(int n)
    {
        string ans;
        while (n)
        {
            --n;
            ans = char(n % 26 + 'A') + ans;
            n /= 26;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.convertToTitle(29);
    return 0;
}