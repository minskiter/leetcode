#include "header.h"

#define rep(i, f, t, s) for (int i = f; i <= t; i += s)
#define repd(i, f, t, s) for (int i = f; i >= t; i -= s)
#define mk(a, b) make_pair(a, b)

// Solution Here
class Solution
{
public:
    vector<int> mostCompetitive(vector<int> &nums, int k)
    {
        stack<int> mostCompetitiveStack;
        int rest = k;
        rep(i, 0, nums.size() - 1, 1)
        {
            if (nums.size() - i <= rest)
            {
                mostCompetitiveStack.emplace(nums[i]);
            }
            else
            {
                while (!mostCompetitiveStack.empty() && mostCompetitiveStack.top() < nums[i] && nums.size() - i > rest)
                {
                    mostCompetitiveStack.pop();
                    rest++;
                }
                if (rest > 0)
                {
                    mostCompetitiveStack.emplace(nums[i]);
                    rest--;
                }
            }
        }
        vector<int> data;
        while (!mostCompetitiveStack.empty())
        {
            data.emplace_back(mostCompetitiveStack.top());
            mostCompetitiveStack.pop();
        }
        reverse(data.begin(), data.end());
        return data;
    }
};

int main()
{
    vector<int> nums = {3, 5, 2, 6};
    return 0;
}