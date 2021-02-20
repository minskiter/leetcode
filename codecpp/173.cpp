#include "header.h"

class BSTIterator
{
private:
    stack<TreeNode *> left;

public:
    BSTIterator(TreeNode *root)
    {
        while (root)
        {
            left.push(root);
            root = root->left;
        }
    }

    int next()
    {
        auto itor = left.top();
        left.pop();
        if (itor->right)
        {
            auto p = itor->right;
            while (p)
            {
                left.push(p);
                p = p->left;
            }
        }
        return itor->val;
    }

    bool hasNext()
    {
        return left.size() > 0;
    }
};

int main()
{
    
    return 0;
}