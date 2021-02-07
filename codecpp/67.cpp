#include "header.h"

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int lena = a.size(), lenb = b.size(), len = min(lena, lenb);
        int c = 0;
        string ans;
        for (int i = 1; i <= len; ++i)
        {
            int temp = a[lena - i] - '0' + b[lenb - i] - '0';
            ans = char(((temp + c) & 1) + '0') + ans;
            c = (temp + c) >> 1;
        }
        for (int i = len + 1; i <= a.size(); ++i)
        {
            int temp = a[lena - i] - '0';
            ans = char(((temp + c) & 1) + '0') + ans;
            c = (temp + c) >> 1;
        }
        for (int i = len + 1; i <= b.size(); ++i)
        {
            int temp = b[lenb - i] - '0';
            ans = char(((temp + c) & 1) + '0') + ans;
            c = (temp + c) >> 1;
        }
        if (c > 0)
        {
            ans = char(c + '0') + ans;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.addBinary("1010", "101");
    return 0;
}