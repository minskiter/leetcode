#include "header.h"

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == nullptr)
        {
            return ans;
        }
        queue<pair<TreeNode *, int>> q;
        q.push(make_pair(root, 0));
        while (!q.empty())
        {
            auto last = q.front();
            q.pop();
            if (ans.size() <= last.second)
            {
                vector<int> temp;
                ans.push_back(temp);
            }
            ans[last.second].push_back(last.first->val);
            if (last.first->left)
            {
                q.push(make_pair(last.first->left, last.second + 1));
            }
            if (last.first->right)
            {
                q.push(make_pair(last.first->right, last.second + 1));
            }
        }
        for (int i=1;i<ans.size();i+=2){
            reverse(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};

int main()
{
    vector<int> tree = {3,9,20,nullint,10,15,7};
    TreeNode * node = new TreeNode();
    node->Parse(tree);
    Solution s;
    fmt::printArray2(s.zigzagLevelOrder(node));
    return 0;
}