#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        int ans = 0;
        map<char, int> values = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        for (int i = 0; i < s.length(); ++i)
        {
            char ch = s[i];
            if (i < s.length() - 1)
            {
                char nxt = s[i + 1];
                switch (ch)
                {
                case 'I':
                    if (nxt == 'V' || nxt == 'X')
                    {
                        ++i;
                        ans += values[nxt] - values[ch];
                    }
                    else
                    {
                        ans += values[ch];
                    }
                    break;
                case 'X':
                    if (nxt == 'L' || nxt == 'C')
                    {
                        ++i;
                        ans += values[nxt] - values[ch];
                    }
                    else
                    {
                        ans += values[ch];
                    }
                    break;
                case 'C':
                    if (nxt == 'D' || nxt == 'M')
                    {
                        ++i;
                        ans += values[nxt] - values[ch];
                    }
                    else
                    {
                        ans += values[ch];
                    }
                    break;
                default:
                    ans += values[ch];
                    break;
                }
            }
            else
            {
                ans += values[ch];
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.romanToInt("MCMXCIV") << endl;
    return 0;
}