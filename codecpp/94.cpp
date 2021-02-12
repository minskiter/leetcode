#include "header.h"

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        search(ans,root);
        return ans;
    }
private:
    void search(vector<int> & ans,TreeNode * root){
        if (root==nullptr) return;
        search(ans,root->left);
        ans.push_back(root->val);
        search(ans,root->right);
    }
};

int main(){
    Solution s;
    vector<int> root={1,2};
    TreeNode * tree = new TreeNode();
    tree->Parse(root);
    fmt::printArray(s.inorderTraversal(tree));
    return 0;
}