#include "header.h"

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root==nullptr) return 0;
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};

int main(){
    vector<int> num = {3,9,20,nullint,nullint,15,7};
    TreeNode * tree=new TreeNode();
    tree->Parse(num);
    Solution s;
    cout << s.maxDepth(tree);
    return 0;
}