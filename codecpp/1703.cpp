#include "header.h"

#define rep(i, f, t, s) for (int i = f; i <= t; i += s)
#define repd(i, f, t, s) for (int i = f; i >= t; i -= s)
#define mk(a, b) make_pair(a, b)

// Solution Here
class Solution
{
public:
    int minMoves(vector<int> &nums, int k)
    {
        int select = 0;   // 初始化选择第一个1做起始靠拢节点
        int l = 1, r = 0; // 左右边界
        vector<int> pos;  // 为1点的位置
        rep(i, 0, nums.size() - 1, 1)
        {
            if (nums[i] == 1)
                pos.emplace_back(i);
        }
        long long mininum = INT_MAX, last_min = 0;
        rep(i, 1, k - 1, 1)
            last_min += pos[i] - pos[0] - (++r);
        mininum = min(last_min, mininum);
        int diff, pmin;
        while (select + r < pos.size())
        {
            while (r > 0)
            {
                diff = pos[select + 1] - pos[select] - 1;
                pmin = last_min + l * diff - r * diff;
                if (pmin <= last_min)
                {
                    ++select;
                    l++;
                    r--;
                    last_min = pmin;
                    mininum = min(mininum, last_min);
                }
                else
                    break;
            }
            if (l == 1)
            {
                if (select + r + 1 >= pos.size())
                    break;
                ++select;
                last_min -= r * (pos[select] - pos[select - 1] - 1);
                last_min += pos[select + r] - pos[select] - r;
            }
            else if (select + r + 1 < pos.size())
            {
                last_min -= pos[select] - pos[select - l + 1] - l + 1;
                --l;
                ++r;
                last_min += pos[select + r] - pos[select] - r;
            }
            else
            {
                break;
            }
            mininum = min(mininum, last_min);
        }
        return mininum;
    }
};

int main()
{
    vector<int> nums = {1,1,1,1,1,1,1,1};
    cout << Solution().minMoves(nums, 3);
    return 0;
}