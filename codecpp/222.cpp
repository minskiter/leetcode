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
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int depth = 1;
        auto p = root;
        for (; p->left != nullptr; depth++, p = p->left)
            ;
        stack<pair<TreeNode *, int>> s;
        s.emplace(root, 1);
        int lost = 0;
        while (!s.empty())
        {
            auto top = s.top();
            if (top.second == depth)
            {
                return (1 << depth) - 1 - lost;
            }
            s.pop();
            if (top.first->left)
                s.emplace(top.first->left, top.second + 1);
            else
            {
                if (top.second == depth - 1)
                    lost++;
            }
            if (top.first->right)
                s.emplace(top.first->right, top.second + 1);
            else
            {
                if (top.second == depth - 1)
                    lost++;
            }
        }
        return (1 << depth) - 1 - lost;
    }
};

int main()
{
    return 0;
}