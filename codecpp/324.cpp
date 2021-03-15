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
// 参考评论区
// 思想:即对映射后的数组执行nth_element(运算符要>)
// 等价于 找中位数后，在三向切分
class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        int n = nums.size();
        std::nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        int mid = nums[n / 2]; // 找出中位数

        int i = 0;
        int j = 0;
        int k = n - 1;

#define a(x) nums[(2 * (i) + 1) % (n | 1)] // 映射后的数组，由于映射是个环，因此映射后的数组三向切分后，原数组自然就交替
        while (j <= k)
        {
            if (a(j) > mid)
            {
                swap(a(i), a(j));
                ++i;
                ++j;
            }
            else if (a(j) < mid)
            {
                swap(a(j), a(k));
                --k;
            }
            else
            {
                ++j;
            }
        }
    }
};

int main()
{
    vector<int> nums = {4, 1, 6, 1, 5, 4};
    Solution().wiggleSort(nums);
    cout << nums << endl;
    return 0;
}