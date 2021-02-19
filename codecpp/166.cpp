#include "header.h"

#define ll long long
class Solution
{
public:
    string fractionToDecimal(ll numerator, ll denominator)
    {
        if (numerator==0) return "0";
        string ans;
        bool sign = (numerator > 0) ^ (denominator > 0);
        numerator = numerator < 0 ? -numerator : numerator;
        denominator = denominator < 0 ? -denominator : denominator;
        ll div = numerator / denominator;
        numerator = numerator % denominator * 10;
        if (div == 0)
            ans.append("0");
        while (div > 0)
        {
            ans = char(div % 10 + '0') + ans;
            div /= 10;
        }
        if (numerator != 0)
            ans.append(".");
        if (sign)
            ans.insert(ans.begin(), '-');
        vector<map<int, int>> is(10);
        int cnt = ans.size() - 1;
        while (numerator > 0)
        {
            ++cnt;
            if (numerator < denominator)
            {
                div = 0;
                numerator *= 10;
            }
            else
            {
                div = numerator / denominator;
                numerator = numerator % denominator * 10;
            }
            if (is[div].find(numerator / 10) == is[div].end())
            {
                is[div][numerator / 10] = cnt;
                ans = ans + (char)(div + '0');
            }
            else
            {
                ans.append(")");
                ans.insert(is[div][numerator / 10], 1, '(');
                break;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.fractionToDecimal(-50, 8);
    return 0;
}