#include "header.h"

class Solution
{
private:
    map<char, char> rightBracket = {
        {')', '('}, {']', '['}, {'}', '{'}};

public:
    bool isValid(string s)
    {
        stack<char> bracketsStack;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                bracketsStack.push(s[i]);
            }
            else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
            {
                if (bracketsStack.size()==0) return false;
                char topBracket = bracketsStack.top();
                if (rightBracket[s[i]] != topBracket)
                {
                    return false;
                }
                bracketsStack.pop();
            }else{
                return false;
            }
        }
        if (bracketsStack.size()>0) return false;
        return true;
    }
};

int main()
{
    Solution s;
    cout << s.isValid(")") << endl;
    return 0;
}