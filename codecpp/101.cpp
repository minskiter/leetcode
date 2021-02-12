#include "header.h"

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root==nullptr) return true;
        return isSameTree(root->left,root->right);
    }
private:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr || q == nullptr)
            return q == p;
        if (p->val != q->val)
            return false;
        return isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
    }
};

int main(){
    vector<int> test = {1,2,2,nullint,3,nullint,3};
    auto tree = new TreeNode();
    tree->Parse(test);
    Solution s;
    cout << s.isSymmetric(tree);
    return 0;
}