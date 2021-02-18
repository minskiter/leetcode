#include "header.h"

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> s;
        vector<int> ans;
        while (root)
        {
            for (; root; root = root->left)
            {
                ans.push_back(root->val);
                s.push(root);
            }
            while (!s.empty() && !s.top()->right)
            {
                s.pop();
            }
            if (!s.empty())
            {
                root = s.top()->right;
                s.pop();
            }
            else
            {
                root = nullptr;
            }
        };
        return ans;
    }
};

int main()
{
    vector<int> root = {1, nullint, 2, nullint, nullint, 3};
    TreeNode *tree = new TreeNode();
    tree->Parse(root);
    Solution s;
    fmt::printArray(s.preorderTraversal(tree));
    return 0;
}