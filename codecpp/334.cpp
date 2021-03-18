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
    bool increasingTriplet(vector<int> &nums)
    {
        vector<int> buffer;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (buffer.empty())
            {
                buffer.emplace_back(nums[i]);
                continue;
            }
            int index = lower_bound(buffer.begin(), buffer.end(), nums[i]) - buffer.begin();
            if (index < buffer.size())
                buffer[index] = nums[i];
            else
                buffer.emplace_back(nums[i]);
            if (buffer.size() == 3)
                return true;
        }
        return false;
    }
};

int main()
{
    return 0;
}