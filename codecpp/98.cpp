#include "header.h"

class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        auto temp = (long long)INT_MIN-1L;
        return inorderBST(root, temp);
    }

private:
    bool inorderBST(TreeNode *root, long long &pre)
    {
        if (root->left && !inorderBST(root->left, pre))
            return false;
        if (pre >= root->val)
            return false;
        pre = root->val;
        if (root->right && !inorderBST(root->right, pre))
            return false;
        return true;
    }
};

int main()
{
    TreeNode *temp = new TreeNode();
    vector<int> num = {5, 1, 7, nullint, nullint, 6, 8};
    temp->Parse(num);
    Solution s;
    cout << s.isValidBST(temp);
    return 0;
}