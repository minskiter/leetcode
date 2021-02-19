#include "header.h"

class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        int l = 0, r = 0, v1 = 0, v2 = 0;
        while (l < version1.size() || r < version2.size())
        {
            v1 = v2 = 0;
            for (; l < version1.size() && version1[l] != '.'; ++l)
                v1 = v1 * 10 + version1[l] - '0';
            for (; r < version2.size() && version2[r] != '.'; ++r)
                v2 = v2 * 10 + version2[r] - '0';
            if (v1 != v2)
                return v1 > v2 ? 1 : -1;
            ++l;
            ++r;
        }
        return 0;
    }
};

int main()
{
    Solution s;
    cout << s.compareVersion("1.0","1.0.1");
    return 0;
}