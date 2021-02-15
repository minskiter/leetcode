#include "header.h"

class Solution
{
public:
    int maxPathSum(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int maxAns = root->val;
        maxRootPathSum(root, maxAns);
        return maxAns;
    }

private:
    int maxRootPathSum(TreeNode *root, int &maxAns)
    {
        if (root == nullptr)
            return 0;
        int left = max(maxRootPathSum(root->left, maxAns), 0);
        int right = max(maxRootPathSum(root->right, maxAns), 0);
        maxAns = max(maxAns, root->val + left + right);
        return max(left, right) + root->val;
    }
};

int main()
{
    vector<int> root = {5, 4, 8, 11, nullint, 13, 4, 7, 2, nullint, nullint, nullint, 1};
    TreeNode *tree = new TreeNode();
    tree->Parse(root);
    tree->PrintTree();
    Solution s;
    cout << s.maxPathSum(tree);
    return 0;
}