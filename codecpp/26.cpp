#include "header.h"

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int newIndex = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] != nums[i - 1])
            {
                nums[newIndex++] = nums[i - 1];
            }
        }
        if (nums.size() > 0)
            nums[newIndex++] = nums[nums.size() - 1];
        return newIndex;
    }
};

int main()
{
    vector<int> test = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    Solution s;
    int len = s.removeDuplicates(test);
    cout << '[';
    for (int i = 0; i < len; ++i)
    {
        cout << test[i];
        if (i != len - 1)
            cout << ',';
    }
    cout << ']' << endl;
    return 0;
}