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
private:
    int compare(vector<int> &num1, vector<int> &num2, int p1, int p2)
    {
        auto len1 = num1.size(), len2 = num2.size();
        while (p1 < len1 && p2 < len2)
        {
            if (num1[p1] != num2[p2])
                return num1[p1] - num2[p2];
            ++p1;
            ++p2;
        }
        return len1 - p1 - (len2 - p2);
    }
    vector<int> merge(vector<int> &num1, vector<int> &num2)
    {
        vector<int> buffer;
        int pt1 = 0, pt2 = 0, len1 = num1.size(), len2 = num2.size();
        while (pt1 < len1 || pt2 < len2)
        {
            auto cmp = compare(num1, num2, pt1, pt2);
            if (cmp > 0)
                buffer.emplace_back(num1[pt1++]);
            else
                buffer.emplace_back(num2[pt2++]);
        }
        return buffer;
    }
    vector<int> maxSeque(vector<int> &num1, int k)
    {
        vector<int> buffer;
        for (int i = 0; i < num1.size(); ++i)
        {
            while (!buffer.empty() && buffer.back() < num1[i] && num1.size() - i > k - buffer.size())
                buffer.pop_back();
            if (buffer.size() < k)
                buffer.emplace_back(num1[i]);
        }
        return buffer;
    }

public:
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<int> maxans;
        for (int i = 0; i <= k; ++i)
        {
            if (i > nums1.size() || k - i > nums2.size())
                continue;
            auto sq1 = maxSeque(nums1, i), sq2 = maxSeque(nums2, k - i);
            auto ans = merge(sq1, sq2);
            if (maxans.size() == 0 || compare(ans, maxans, 0, 0) > 0)
                maxans = move(ans);
        }
        return maxans;
    }
};

int main()
{
    vector<int> num1 = {3, 4, 6, 5}, num2 = {9, 1, 2, 5, 8, 3};
    cout << Solution().maxNumber(num1, num2, 5);
    return 0;
}