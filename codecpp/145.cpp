#include "header.h"

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode *> s;
        vector<int> ans;
        if (root==nullptr) return ans;
        s.push(root);
        while (!s.empty())
        {
            auto node = s.top();
            s.pop();
            if (node->left) s.push(node->left);
            if (node->right) s.push(node->right);
            ans.push_back(node->val);
        };
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main(){
    vector<int> root = {1, nullint, 2, nullint, nullint, 3};
    TreeNode *tree = new TreeNode();
    tree->Parse(root);
    Solution s;
    fmt::printArray(s.postorderTraversal(tree));
    return 0;
}