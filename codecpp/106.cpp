#include "header.h"

class Solution
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int index = inorder.size() - 1;
        return buildNode(inorder, postorder, index, 0, index);
    }

private:
    TreeNode *buildNode(vector<int> &inorder, vector<int> &postorder, int &index, int l, int r)
    {
        if (l > r)
        {
            return nullptr;
        }
        if (l == r)
        {
            return new TreeNode(postorder[index--]);
        }
        auto node = new TreeNode(postorder[index--]);
        for (int i = l; i <= r; ++i)
        {
            if (postorder[index+1] == inorder[i])
            {
                node->right = buildNode(inorder, postorder, index, i + 1, r);
                node->left = buildNode(inorder, postorder, index, l, i - 1);
                break;
            }
        }
        return node;
    }
};

int main()
{
    Solution s;
    vector<int> inorder = {1,2};
    vector<int> postorder = {2,1};
    fmt::printArray(s.buildTree(inorder, postorder)->ToVector());
    cout << endl;
    s.buildTree(inorder, postorder)->PrintTree();
    return 0;
}