#include "header.h"

class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return buildBST(nums, 0, nums.size() - 1);
    }

private:
    TreeNode *buildBST(vector<int> &nums, int l, int r)
    {
        if (l > r)
            return nullptr;
        if (l == r)
            return new TreeNode(nums[l]);
        int mid = (l + r) >> 1;
        auto node = new TreeNode(nums[mid]);
        node->left = buildBST(nums, l, mid - 1);
        node->right = buildBST(nums, mid + 1, r);
        return node;
    }
};

int main()
{
    Solution s;
    vector<int> temp={-10,-3,0,5,9};
    s.sortedArrayToBST(temp)->PrintTree();
    return 0;
}