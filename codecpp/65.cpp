#include "header.h"

class Solution
{
public:
    bool isNumber(string s)
    {
        bool sign = false;
        if (s[0] == '-' || s[0] == '+')
        {
            sign = true;
        }
        bool dot = false;
        bool e = false;
        bool needNumber = true;
        for (int i = sign; i < s.size(); ++i)
        {
            if (s[i] == '-' || s[i] == '+')
            {
                return false;
            }
            else if (s[i] == 'e' || s[i] == 'E')
            {
                if (e || needNumber)
                {
                    return false;
                }
                e = true;
                needNumber = true;
                if (i + 1 >= s.size())
                {
                    return false;
                }
                if (s[i + 1] == '-' || s[i + 1] == '+')
                {
                    ++i;
                }
            }
            else if (s[i] == '.')
            {
                if (e || dot)
                {
                    return false;
                }
                dot = true;
            }
            else if (s[i] >= '0' && s[i] <= '9')
            {
                needNumber = false;
            }
            else
            {
                return false;
            }
        }
        if (needNumber)
        {
            return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<string> number = {
        "2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789","0",".1","-.1","1.","005047e+6","46.e3",".2e81"};
    vector<string> notnumber = {
        "abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53","e",".","..2","+e","+3. e04116"};
    for (int i = 0; i < number.size(); ++i)
    {
        if (!s.isNumber(number[i]))
        {
            cout << "error(number):" << number[i] << endl;
        }
    }
    for (int i = 0; i < notnumber.size(); ++i)
    {
        if (s.isNumber(notnumber[i]))
        {
            cout << "error(notnumber):" << notnumber[i] << endl;
        }
    }
    return 0;
}