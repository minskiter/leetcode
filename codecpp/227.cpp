#include "header.h"

#define rep(i, f, t, s) for (int i = f; i <= (int)t; i += s)
#define repd(i, f, t, s) for (int i = f; i >= (int)t; i -= s)
#define mk(a, b) make_pair(a, b)
#define sqr(a) ((a) * (a))
template <class Ty1, class Ty2>
inline const pair<Ty1, Ty2> operator+(const pair<Ty1, Ty2> &p1, const pair<Ty1, Ty2> &p2)
{
    return mk(p1.first + p2.first, p1.second + p2.second);
}
template <class Ty1, class Ty2>
inline const pair<Ty1, Ty2> operator-(const pair<Ty1, Ty2> &p1, const pair<Ty1, Ty2> &p2)
{
    return mk(p1.first - p2.first, p1.second - p2.second);
}
template <class Ty1, class Ty2>
bool inner(pair<Ty1, Ty2> pos, pair<Ty1, Ty2> leftTop, pair<Ty1, Ty2> rightBottom)
{
    if (pos.first >= leftTop.first && pos.second >= leftTop.second)
    {
        if (pos.first < rightBottom.first && pos.second < rightBottom.second)
        {
            return true;
        }
    }
    return false;
}

// Solution Here
class Solution
{
public:
    int calculate(string s)
    {
        stack<long long> nums;
        stack<char> operators;
        auto ans = 0LL;
        auto oper = '+';
        auto num = 0LL;
        s.append("+0");
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] >= '0' && s[i] <= '9')
                num = num * 10 + (s[i] - '0');
            else if (s[i] == '-' || s[i] == '+')
            {
                if (oper == '*')
                    ans *= num;
                else if (oper == '/')
                    ans /= num;
                else if (oper == '+')
                    ans += num;
                else if (oper == '-')
                    ans -= num;
                while (!operators.empty())
                {
                    if (operators.top() == '+')
                        ans += nums.top();
                    else if (operators.top() == '-')
                        ans = nums.top() - ans;
                    operators.pop();
                    nums.pop();
                }
                oper = s[i];
                num = 0;
            }
            else if (s[i] == '*' || s[i] == '/')
            {
                if (oper == '+' || oper == '-')
                {
                    operators.emplace(oper);
                    nums.emplace(ans);
                    ans = num;
                }
                else if (oper == '*')
                {
                    ans *= num;
                }
                else if (oper == '/')
                {
                    ans /= num;
                }
                oper = s[i];
                num = 0;
            }
        }
        return ans;
    }
};

int main()
{
    cout << Solution().calculate(" 2*3*4-7/2*4 ");
    return 0;
}