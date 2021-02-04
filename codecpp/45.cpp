#include "header.h"

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        vector<int> cost(nums.size(), INT_MAX);
        cost[0] = 0;
        q.push(make_pair(0, 0));
        for (int i = 1; i < nums.size(); ++i)
        {
            while (q.size() > 0 && nums[q.top().second] + q.top().second < i)
            {
                q.pop();
            }
            if (q.size() > 0)
            {
                cost[i] = cost[q.top().second] + 1;
                q.push(make_pair(cost[i], i));
            }
        }
        return cost[nums.size() - 1];
    }
};

int main()
{
    vector<int> test = {0, 0, 0, 0, 0};
    Solution s;
    cout << s.jump(test);
    return 0;
}