#include "header.h"

class Solution
{
public:
    string minWindow(string s, string t)
    {
        vector<int> ascii(256), temp(256);
        int cnt = 0, maxCnt = 0;
        for (int i = 0; i < t.size(); ++i)
        {
            ascii[t[i]]++;
            if (ascii[t[i]] == 1)
                cnt++;
        }
        int left = 0, right = -1;
        int lenS = s.size();
        int minL = 0, minR = lenS + 2;
        while (right < lenS)
        {
            while (right < lenS && maxCnt < cnt)
            {
                ++right;
                if (right==lenS) break;
                temp[s[right]]++;
                if (temp[s[right]] == ascii[s[right]] && ascii[s[right]] > 0)
                {
                    maxCnt++;
                }
            }
            while (left <= right && maxCnt >= cnt)
            {
                if (right - left < minR - minL)
                {
                    minR = right;
                    minL = left;
                }
                temp[s[left]]--;
                if (temp[s[left]] == ascii[s[left]]-1)
                {
                    maxCnt--;
                }
                left++;
            }
        }
        if (minR == lenS + 2)
        {
            return "";

        }
        else
        {
            return s.substr(minL, minR - minL + 1);
        }
    }
};

int main()
{
    Solution s;
    cout << s.minWindow("","a");
    return 0;
}