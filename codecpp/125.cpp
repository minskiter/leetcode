#include "header.h"

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int l = 0, r = s.size();
        while (l <= r)
        {
            while (l < s.size() && !translate(s[l]))
                l++;
            while (r >= 0 && !translate(s[r]))
                r--;
            if (l <= r)
            {
                if (s[l++] != s[r--])
                    return false;
            }
        }
        return true;
    }

private:
    bool translate(char &ch)
    {
        if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            if (ch >= 'A' && ch <= 'Z')
            {
                ch += 'a' - 'A';
            }
            return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    cout << s.isPalindrome("race a car");
    return 0;
}