#include "header.h"

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int l = 0, r = numbers.size() - 1;
        while (l < r)
        {
            if (numbers[l] + numbers[r] > target)
                r--;
            else if (numbers[l] + numbers[r] == target)
                return vector<int>{l + 1, r + 1};
            else
                l++;
        }
        return vector<int>{};
    }
};

int main()
{
    vector<int> numbers = {2, 7, 11, 15};
    Solution s;
    fmt::printArray(s.twoSum(numbers, 18));
    return 0;
}