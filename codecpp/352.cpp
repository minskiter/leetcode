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
class SummaryRanges
{
    set<int> left, right;

public:
    /** Initialize your data structure here. */
    SummaryRanges()
    {
    }

    void addNum(int val)
    {
        // 判断val是否在原来的区间中
        auto itor = right.lower_bound(val);
        if (itor != right.end())
        {
            auto left_itor = left.upper_bound(*itor);
            left_itor = prev(left_itor);
            if (*left_itor <= val && val <= *itor)
            {
                // 在原始区间中，因此不需要处理
                return;
            }
            // 必须处理，上述为右侧区间，判断是否需要合并
            if (*left_itor == val + 1)
            {
                // 判断左侧区间是否同样需要合并
                if (itor != right.begin() && *prev(itor) == val - 1)
                {
                    // 合并两侧区间
                    auto new_l = *prev(left_itor), new_r = *itor;
                    right.erase(*prev(itor));
                    left.erase(*left_itor);
                    return;
                }
                // 只合并右侧区间
                left.erase(*left_itor);
                left.insert(val);
                return;
            }
        }
        if (right.size() != 0)
        {
            // 判断左侧区间是否需要合并
            itor = prev(itor);
            if (*itor == val - 1)
            {
                // 合并左侧区间
                right.erase(*itor);
                right.emplace(val);
            }
            return;
        }
        // 不需要合并
        right.emplace(val);
        left.emplace(val);
    }

    vector<vector<int>> getIntervals()
    {
        auto left_ptr = left.begin(), right_ptr = right.begin();
        vector<vector<int>> tmp;
        while (left_ptr != left.end())
        {
            tmp.emplace_back(vector<int>{*left_ptr, *right_ptr});
            left_ptr = next(left_ptr);
            right_ptr = next(right_ptr);
        }
        return tmp;
    }
};

int main()
{
    return 0;
}