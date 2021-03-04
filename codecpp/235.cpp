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
// 可合并搜索，终止条件为一左一右
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        unordered_set<int> vis;
        vis.emplace(root->val);
        auto itor = root;
        while (itor->val != p->val)
        {
            if (p->val < itor->val)
                itor = itor->left;
            else
                itor = itor->right;
            vis.insert(itor->val);
        }
        itor = root;
        auto ans = itor;
        while (itor->val != q->val)
        {
            if (q->val < itor->val)
                itor = itor->left;
            else
                itor = itor->right;
            if (vis.find(itor->val) == vis.end())
                break;
            ans = itor;
        }
        return ans;
    }
};

int main()
{
    return 0;
}