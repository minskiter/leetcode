#include "header.h"

#define rep(i, f, t, s) for (int i = f; i <= (int)t; i += s)
#define repd(i, f, t, s) for (int i = f; i >= (int)t; i -= s)
#define mk(a, b) make_pair(a, b)
#define sqr(a) ((a) * (a))
template <class Ty1, class Ty2>
inline const pair<Ty1, Ty2> operator+(const pair<Ty1, Ty2> &p1, const pair<Ty1, Ty2> &p2)
{
    return mk(p1.first + p2.first, p1.second + p2.second);
}
template <class Ty1, class Ty2>
inline const pair<Ty1, Ty2> operator-(const pair<Ty1, Ty2> &p1, const pair<Ty1, Ty2> &p2)
{
    return mk(p1.first - p2.first, p1.second - p2.second);
}
template <class Ty1, class Ty2>
bool inner(pair<Ty1, Ty2> pos, pair<Ty1, Ty2> leftTop, pair<Ty1, Ty2> rightBottom)
{
    if (pos.first >= leftTop.first && pos.second >= leftTop.second)
    {
        if (pos.first < rightBottom.first && pos.second < rightBottom.second)
        {
            return true;
        }
    }
    return false;
}

// Solution Here
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        unordered_set<int> vis1, vis2;
        search(root, p, vis1);
        search(root, q, vis2);
        while (root)
        {
            if (root->left && vis1.find(root->left->val) != vis1.end() && vis2.find(root->left->val) != vis2.end())
                root = root->left;
            else if (root->right && vis1.find(root->right->val) != vis1.end() && vis2.find(root->right->val) != vis2.end())
                root = root->right;
            else
                break;
        }
        return root;
    }

private:
    bool search(TreeNode *p, TreeNode *target, unordered_set<int> &vis)
    {
        if (p==nullptr) return false;
        if (p->val == target->val)
            return true;
        if (p->left)
        {
            vis.emplace(p->left->val);
            if (search(p->left, target, vis))
                return true;
            vis.erase(p->left->val);
        }
        if (p->right)
        {
            vis.emplace(p->right->val);
            if (search(p->right, target, vis))
                return true;
            vis.erase(p->right->val);
        }
        return false;
    }
};

int main()
{
    return 0;
}