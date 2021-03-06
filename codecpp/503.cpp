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
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        if (nums.size()==0) return vector<int>();
        vector<int> res(nums.size(), -1);
        stack<int> pos;
        for (int i = 0; i < nums.size() * 2; ++i)
        {
            while (!pos.empty() && nums[pos.top()] < nums[i%nums.size()])
            {
                res[pos.top()] = nums[i%nums.size()];
                pos.pop();
            }
            if (i < nums.size())
                pos.emplace(i);
        }
        return res;
    }
};

int main()
{
    return 0;
}