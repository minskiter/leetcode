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
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<int> ptr(nums1.size());
        auto cmp = [](const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b) {
            if (a.second.first + a.second.second == b.second.first + b.second.second)
            {
                return a.second.first > b.second.first;
            }
            return a.second.first + a.second.second < b.second.first + b.second.second;
        };
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(cmp)> q(cmp);
        for (int i = 0; i < nums1.size(); ++i)
            q.push(make_pair(i, make_pair(nums1[i], nums1[ptr[i]])));
        vector<vector<int>> ans;
        while (!q.empty() && ans.size() < k)
        {
            auto top = q.top();
            q.pop();
            ans.emplace_back(vector<int>{top.second.first, top.second.second});
            if (ptr[top.first] + 1 < nums2.size())
            {
                ++ptr[top.first];
                top.second.second = nums2[ptr[top.first]];
                q.push(top);
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}