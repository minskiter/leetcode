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
        stack<char> operators;
        stack<long long> nums;
        auto ans = 0LL;
        auto num = 0LL;
        auto oper = '+';
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                num = num * 10 + (s[i] - '0');
            }
            else if (s[i] == '+' || s[i] == '-')
            {
                if (oper == '+')
                    ans += num;
                else if (oper == '-')
                    ans -= num;
                oper = s[i];
                num = 0;
            }
            else if (s[i] == '(')
            {
                nums.emplace(ans);
                operators.emplace(oper);
                ans = 0;
                num = 0;
                oper = '+';
            }
            else if (s[i] == ')')
            {
                if (oper == '+')
                    ans += num;
                else if (oper == '-')
                    ans -= num;
                if (operators.top() == '+')
                    ans = nums.top() + ans;
                else if (operators.top() == '-')
                    ans = nums.top() - ans;
                operators.pop();
                nums.pop();
                num = 0;
                oper = '+';
            }
        }
        if (oper == '+')
            ans += num;
        else if (oper == '-')
            ans -= num;
        return ans;
    }
};

int main()
{
    cout << Solution().calculate("2147483647");
    return 0;
}