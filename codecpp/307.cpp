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
class NumArray
{
    vector<int> *data;
    int sum(int index)
    {
        int result = 0;
        while (index>0)
        {
            result += (*data)[index - 1];
            index -= index & -index;
        }
        return result;
    }

public:
    NumArray(vector<int> &nums)
    {
        data = &nums;
        for (int i = (int)nums.size() - 1; i >= 0; --i)
            update((i + 1) + ((i + 1) & -(i + 1)) - 1, nums[i] , true);
    }

    void update(int index, int val, bool flag=false)
    {
        if (!flag)
            val -= sumRange(index, index);
        ++index;
        while (index <= data->size())
        {
            (*data)[index - 1] += val;
            index += (index & -index);
        }
    }

    int sumRange(int left, int right)
    {
        if (left == 0)
            return sum(right + 1);
        return sum(right + 1) - sum(left);
    }
};

int main()
{
    vector<int> nums = {1, 3, 5};
    NumArray array(nums);
    cout << nums << endl;
    return 0;
}