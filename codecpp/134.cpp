// TODO: 标准做法一次遍历法
#include "header.h"

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        map<int, int> remain;
        vector<int> remainArr;
        int sum = 0;
        for (int i = 0; i < gas.size(); ++i)
        {
            sum = sum + gas[i] - cost[i];
            remainArr.push_back(sum);
            if (remain.find(-sum) == remain.end())
                remain[-sum] = 1;
            else
                remain[-sum]++;
        }
        if (remain.upper_bound(0) == remain.end())
            return 0;
        int diff = 0;
        for (int i = 1; i < gas.size(); ++i)
        {
            if (remain[-remainArr[i - 1]] == 1)
                remain.erase(-remainArr[i - 1]);
            else
                remain[-remainArr[i - 1]]--;
            diff = -remainArr[i - 1];
            remainArr[i - 1] = remainArr[(gas.size() + i - 2) % gas.size()] + gas[i - 1] - cost[i - 1];
            if (remain.find(-remainArr[i - 1]) == remain.end())
                remain[-remainArr[i - 1]] = 1;
            else
                remain[-remainArr[i - 1]]++;
            if (remain.upper_bound(diff) == remain.end())
                return i;
        }
        return -1;
    }
};

int main()
{
    vector<int> gas = {2, 3, 4};
    vector<int> cost = {3, 4, 3};
    Solution s;
    cout << s.canCompleteCircuit(gas, cost);
    return 0;
}