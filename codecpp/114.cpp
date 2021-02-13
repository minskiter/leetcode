// 评论区最简代码
#include "header.h"

class Solution
{
public:
    // 递归非原地算法
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
            return;
        flatten(root->right);
        flatten(root->left);
        root->right = last;
        root->left = nullptr;
        last=root;
    }
private:
    TreeNode * last=nullptr; 
};

int main()
{
    vector<int> root = {1, 2, 5, 3, 4, nullint, 6};
    TreeNode *tree = new TreeNode();
    tree->Parse(root);
    Solution s;
    s.flatten(tree);
    tree->PrintTree();
    return 0;
}