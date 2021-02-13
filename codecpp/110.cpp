#include "header.h"

class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        root->val = 1;
        if (root->left)
        {
            if (!isBalanced(root->left))
                return false;
            root->val = max(root->val, root->left->val + 1);
        }
        if (root->right)
        {
            if (!isBalanced(root->right))
                return false;
            if (abs(root->val - root->right->val - 1) > 1)
            {
                return false;
            }
            root->val = max(root->val, root->right->val + 1);
        }
        else
        {
            if (root->val > 2)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<int> root = {1, 2, 2, 3, 3, nullint, nullint, 4, 4};
    TreeNode *tree = new TreeNode();
    tree->Parse(root);
    cout << s.isBalanced(tree) << endl;
    tree->PrintTree();
    return 0;
}