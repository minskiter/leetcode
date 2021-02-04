#include "header.h"

class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
        {
            return "1";
        }
        string temp = countAndSay(n - 1);
        char ch = ' ';
        int cnt = 0;
        string ans = "";
        char buffer[200];
        for (int i = 0; i < temp.size(); ++i)
        {
            if (temp[i] != ch)
            {
                if (cnt > 0)
                {
                    itoa(cnt * 10 + ch - '0', buffer, 10);
                    ans += buffer;
                }
                ch = temp[i];
                cnt = 1;
            }
            else
            {
                cnt++;
            }
        }
        if (cnt > 0)
        {
            itoa(cnt * 10 + ch - '0', buffer, 10);
            ans += buffer;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.countAndSay(30);
    return 0;
}