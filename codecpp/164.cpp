#include "header.h"

class Solution
{
public:
    int maximumGap(vector<int> &nums)
    {
        if (nums.size() < 2)
            return 0;
        int maxinum = *max_element(nums.begin(), nums.end());
        int mininum = *min_element(nums.begin(), nums.end());
        int d = max<int>((maxinum - mininum) / (nums.size() - 1), 1), pos;
        vector<pair<int, int>> bucket((maxinum - mininum) / d + 1, make_pair(INT_MAX, -1));
        for (auto num : nums)
        {
            pos = (num - mininum) / d;
            bucket[pos].first = min(bucket[pos].first, num);
            bucket[pos].second = max(bucket[pos].second, num);
        }
        int result = 0, pre = 0;
        for (int i = 1; i < bucket.size(); ++i)
        {
            if (bucket[i].second != -1 && bucket[pre].second != -1)
                result = max(result, bucket[i].first - bucket[pre].second);
            pre = bucket[i].second == -1 ? pre : i;
        }
        return result;
    }
};

int main()
{
    vector<int> nums{1, 1, 1, 2};
    Solution s;
    cout << s.maximumGap(nums);
    return 0;
}