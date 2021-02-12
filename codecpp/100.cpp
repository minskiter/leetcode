#include "header.h"

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr || q == nullptr)
            return q == p;
        if (p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main()
{
    Solution s;
    vector<int> p = {1, 2, 3}, q = {1, 2, 3};
    TreeNode *pt = new TreeNode(), *qt = new TreeNode();
    pt->Parse(p);
    qt->Parse(q);
    cout << s.isSameTree(pt, qt) << endl;
    return 0;
}