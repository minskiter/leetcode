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

class BinaryIndexTree
{
private:
    int _size;
    vector<int> data;

public:
    BinaryIndexTree(int size) : _size(size + 1), data(size + 1)
    {
    }

    void add(int index, int val)
    {
        for (; index < _size; index += index & (-index))
            data[index] += val;
    }
    int prefixSum(int index)
    {
        int sum = 0;
        for (; index > 0; index -= index & (-index))
            sum += data[index];
        return sum;
    }
};

// Solution Here
class Solution
{
public:
    int countRangeSum(vector<int> &nums, int lower, int upper)
    {
        vector<long long> sum(nums.size());
        for (int i = 0; i < nums.size(); ++i)
            sum[i] = (i > 0 ? sum[i - 1] : 0) + nums[i];

        sort(sum.begin(), sum.end());
        BinaryIndexTree tree(nums.size());
        for (int i = 1; i <= nums.size(); ++i)
            tree.add(i, 1);
        long long prefix = 0;
        int cnt = 0;
        vector<int> nxt(nums.size() + 1);
        for (int i = 0; i < nums.size(); ++i)
            nxt[i] = -1;
        for (int i = 0; i < nums.size(); ++i)
        {
            int lowerIndex = lower_bound(sum.begin(), sum.end(), lower + prefix) - sum.begin();
            int upperIndex = upper_bound(sum.begin(), sum.end(), upper + prefix) - sum.begin();
            cnt += tree.prefixSum(upperIndex) - tree.prefixSum(lowerIndex);
            prefix += nums[i];
            lowerIndex = lower_bound(sum.begin(), sum.end(), prefix) - sum.begin();
            auto tmp = lowerIndex;
            while (nxt[lowerIndex] != -1)
                lowerIndex = nxt[lowerIndex];
            nxt[tmp] = lowerIndex + 1;
            tree.add(lowerIndex + 1, -1);
        }
        return cnt;
    }
};

int main()
{
    vector<int> nums = {-2, 5, -1};
    cout << Solution().countRangeSum(nums, -2, 2);
    return 0;
}