#include "header.h"

class Solution
{
public:
    string reverseWords(string s)
    {
        reverse(s.begin(), s.end());
        int j = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] != ' ' || (i > 0 && s[i] == ' ' && s[i - 1] != ' '))
                s[j++] = s[i];
        }
        while (s[j - 1] == ' ')
            --j;
        s.resize(j);
        auto l = s.begin(), r = s.begin();
        while (r != s.end())
        {
            while (r != s.end() && *r != ' ')
                r = next(r);
            reverse(l, r);
            if (r == s.end())
                break;
            r = next(r);
            l = r;
        }
        return s;
    }
};

int main()
{
    Solution s;
    cout << s.reverseWords("a good   example");
    return 0;
}