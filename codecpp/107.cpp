#include "header.h"

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        search(root,ans,0);
        reverse(ans.begin(),ans.end());
        return ans;
    }
private:
    void search(TreeNode * root,vector<vector<int>> &ans,int deepth){
        if (root==nullptr) return;
        if (deepth>=ans.size()){
            ans.push_back(vector<int>());
        }
        ans[deepth].push_back(root->val);
        search(root->left,ans,deepth+1);
        search(root->right,ans,deepth+1);
    }
};

int main(){
    Solution s;
    vector<int> treeArr = {3,9,20,nullint,nullint,15,7};
    TreeNode * node = new TreeNode();
    node->Parse(treeArr);
    fmt::printArray2(s.levelOrderBottom(node));
    return 0;
}