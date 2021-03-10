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
// 优化空间，预处理remove的最小的大小，可以利用遍历实现
class Solution
{
public:
    vector<string> removeInvalidParentheses(string s)
    {
        unordered_set<string> ansV;
        string ans;
        int remove = s.size(), left = 0;
        search(ansV, remove, s, ans, 0, left);
        vector<string> ansBuffer;
        for (auto item : ansV)
            ansBuffer.emplace_back(item);
        return ansBuffer;
    }

private:
    void search(unordered_set<string> &ansV, int &remove, string &s, string &ans, int deepth, int &left)
    {
        if (deepth - ans.size() > remove)
            return;
        if (deepth == s.size())
        {
            if (left != 0)
                return;
            if (deepth - ans.size() < remove)
                ansV.clear();
            ansV.emplace(ans);
            remove = deepth - ans.size();
            return;
        }
        if (s[deepth] == '(' || s[deepth] == ')')
        {
            // remove
            search(ansV, remove, s, ans, deepth + 1, left);
            // add
            if (s[deepth] == '(')
            {
                left++;
                ans.push_back(s[deepth]);
                search(ansV, remove, s, ans, deepth + 1, left);
                ans.pop_back();
                left--;
            }
            else
            {
                if (left <= 0)
                    return;
                --left;
                ans.push_back(s[deepth]);
                search(ansV, remove, s, ans, deepth + 1, left);
                ans.pop_back();
                ++left;
            }
        }
        else
        {
            ans.push_back(s[deepth]);
            search(ansV, remove, s, ans, deepth + 1, left);
            ans.pop_back();
        }
    }
};

int main()
{
    cout << Solution().removeInvalidParentheses("(a)())()");
    return 0;
}