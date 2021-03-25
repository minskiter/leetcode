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
    bool find132pattern(vector<int> &nums)
    {
        int *mins = new int[nums.size()];
        memset(mins, 0x3f, sizeof(int) * nums.size());
        stack<int> s;
        mins[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i)
            mins[i] = min(mins[i - 1], nums[i]);
        for (int i = (int)nums.size() - 1; i > 0; --i)
        {
            if (!s.empty() && s.top() <= mins[i])
                s.pop();
            if (nums[i] > mins[i])
            {
                if (s.empty())
                    s.emplace(nums[i]);
                else if (nums[i] < s.top())
                    return true;
                else
                {
                    s.pop();
                    s.emplace(nums[i]);
                }
            }
        }
        return false;
    }
};

int main()
{
    return 0;
}