#include "header.h"

#define rep(i, f, t, s) for (int i = f; i <= t; i += s)
#define repd(i, f, t, s) for (int i = f; i >= t; i -= s)
#define mk(a,b) make_pair(a,b)

// Solution Here
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root==nullptr) return vector<int>();
        stack<pair<TreeNode *,int>> treeStack;
        pair<TreeNode *,int> cur;
        vector<int> ans;
        treeStack.push(mk(root,1));
        while (!treeStack.empty()){
            cur = treeStack.top();
            if (cur.second>ans.size()){
                ans.push_back(cur.first->val);
            }
            treeStack.pop();
            if (cur.first->left) treeStack.push(mk(cur.first->left,cur.second+1));
            if (cur.first->right) treeStack.push(mk(cur.first->right,cur.second+1));
        }
        return ans;
    }
};

int main()
{
    return 0;
}