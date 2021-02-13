#include "header.h"

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if (root==nullptr){
            return ans;
        }
        if (root->left==nullptr && root->right==nullptr){
            if (targetSum==root->val){
                ans.push_back(vector<int>(1,root->val));
            }
            return ans;
        }
        auto left = pathSum(root->left,targetSum-root->val);
        for (int i=0;i<left.size();++i){
            left[i].insert(left[i].begin(),root->val);
            ans.push_back(left[i]);
        }
        auto right = pathSum(root->right,targetSum-root->val);
        for (int i=0;i<right.size();++i){
            right[i].insert(right[i].begin(),root->val);
            ans.push_back(right[i]);
        }
        return ans;
    }
};

int main(){
    return 0;
}