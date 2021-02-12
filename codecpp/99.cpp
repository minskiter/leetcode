#include "header.h"

class Solution
{
public:
    void recoverTree(TreeNode *root)
    {
        vector<TreeNode *> nodes;
        TreeNode * pre = new TreeNode(INT_MIN);
        TreeNode * temp = pre;
        search(nodes,root,pre);
        delete temp;
        if (nodes.size()==4){
            swap(nodes[0]->val,nodes[3]->val);
        }else{
            swap(nodes[0]->val,nodes[1]->val);
        }
    }

private:
    void search(vector<TreeNode *> &nodes, TreeNode *root, TreeNode *&pre)
    {
        if (root->left)
        {
            search(nodes, root->left, pre);
        }
        if (pre->val>root->val){
            nodes.push_back(pre);
            nodes.push_back(root);
        }
        pre = root;
        if (root->right)
        {
            search(nodes, root->right, pre);
        }
    }
};

int main()
{
    Solution s;
    vector<int> tree = {6,1,4,nullint,nullint,3,2};
    TreeNode * node = new TreeNode();
    node->Parse(tree);
    node->PrintInorder();
    s.recoverTree(node);
    node->PrintInorder();
    return 0;
}