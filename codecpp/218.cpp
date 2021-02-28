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
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        vector<pair<int, int>> poses;
        multiset<int> heights={0};
        for (int i = 0; i < buildings.size(); ++i)
        {
            poses.emplace_back(make_pair(buildings[i][0], -buildings[i][2]));
            poses.emplace_back(make_pair(buildings[i][1], buildings[i][2]));
        }
        sort(poses.begin(),poses.end());
        vector<vector<int>> ans;
        vector<int> last(2);
        for (auto &pos : poses)
        {
            if (pos.second < 0)
                heights.emplace(-pos.second);
            else
                heights.erase(heights.find(pos.second));
            auto maxheight = *heights.rbegin();
            if (last[1] != maxheight)
            {
                last[0] = pos.first;
                last[1] = maxheight;
                ans.emplace_back(last);
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> buildings = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
    fmt::printArray2(Solution().getSkyline(buildings));
    return 0;
}