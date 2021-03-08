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
    void search(long long pre, int f, long long sum, int target, vector<string> &ansV, string &ans, int deepth, string &num)
    {
        if (deepth == num.size())
        {
            if (pre + f * sum == target)
                ansV.emplace_back(ans);
            return;
        }
        auto eval = 0LL;
        auto loop = num[deepth] == '0' ? 1 : num.size() - deepth;
        int len = ans.size();
        for (int i = 1; i <= loop; ++i)
        {
            eval = eval * 10LL + (num[deepth + i - 1] - '0');
            ans.append("*").append(num.begin() + deepth, num.begin() + i);
            search(pre, f, sum * eval, target, ansV, ans, deepth + i, num);
            ans.resize(len);
            ans.append("+").append(num.begin() + deepth, num.begin() + i);
            search(pre + f * sum, 1, eval, target, ansV, ans, deepth + i, num);
            ans.resize(len);
            ans.append("-").append(num.begin() + deepth, num.begin() + i);
            search(pre + f * sum, -1, eval, target, ansV, ans + "-" + num.substr(deepth, i), deepth + i, num);
            ans.resize(len);
        }
    }

public:
    vector<string> addOperators(string num, int target)
    {
        vector<string> ansV;
        auto eval = 0LL;
        auto loop = num[0] == '0' ? 1 : num.size();
        string ans;
        ans.reserve(num.size() * 2);
        for (int i = 1; i <= loop; ++i)
        {
            eval = eval * 10LL + (num[i - 1] - '0');
            ans.append(num.begin(), num.begin() + i);
            search(0, 1, eval, target, ansV, ans, i, num);
            ans.resize(0);
        }
        return ansV;
    }
};

int main()
{
    cout << Solution().addOperators("123", 6);
    return 0;
}