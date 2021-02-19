#include "header.h"

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> nums;
        for (int i = 0; i < tokens.size(); ++i)
        {
            if ((tokens[i].size() > 0 && tokens[i][0] >= '0' && tokens[i][0] <= '9') || (tokens[i].size() > 1 && tokens[i][1] >= '0' && tokens[i][1] <= '9'))
            {
                // number
                int num = 0;
                int sign = tokens[i][0] == '-' ? -1 : 1;
                for (int j = 0; j < tokens[i].size(); ++j)
                {
                    if (tokens[i][j] >= '0' && tokens[i][j] <= '9')
                        num = num * 10 + tokens[i][j] - '0';
                }
                nums.emplace(sign * num);
            }
            else
            {
                if (tokens[i].size() > 0)
                {
                    // operator
                    int passive, subject;
                    passive = nums.top();
                    nums.pop();
                    subject = nums.top();
                    nums.pop();
                    switch (tokens[i][0])
                    {
                    case '-':
                        nums.emplace(subject - passive);
                        break;
                    case '+':
                        nums.emplace(subject + passive);
                        break;
                    case '/':
                        nums.emplace(subject / passive);
                        break;
                    case '*':
                        nums.emplace(subject * passive);
                        break;
                    default:
                        break;
                    }
                }
            }
        }
        return nums.empty() ? 0 : nums.top();
    }
};

int main()
{
    vector<string> PolishNotation = {"-78", "-33", "196", "+", "-19", "-", "115", "+", "-", "-99", "/", "-18", "8", "*", "-86", "-", "-", "16", "/", "26", "-14", "-", "-", "47", "-", "101", "-", "163", "*", "143", "-", "0", "-", "171", "+", "120", "*", "-60", "+", "156", "/", "173", "/", "-24", "11", "+", "21", "/", "*", "44", "*", "180", "70", "-40", "-", "*", "86", "132", "-84", "+", "*", "-", "38", "/", "/", "21", "28", "/", "+", "83", "/", "-31", "156", "-", "+", "28", "/", "95", "-", "120", "+", "8", "*", "90", "-", "-94", "*", "-73", "/", "-62", "/", "93", "*", "196", "-", "-59", "+", "187", "-", "143", "/", "-79", "-89", "+", "-"};
    Solution s;
    cout << s.evalRPN(PolishNotation);
    return 0;
}