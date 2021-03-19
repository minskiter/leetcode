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
    vector<int> maxNode(TreeNode *root)
    {
        if (root == nullptr)
            return vector<int>(2, 0);
        vector<int> value(2);
        // 包括该点
        value[0] += root->val;
        if (root->left)
        {
            auto tmp = maxNode(root->left);
            value[0] += tmp[1];
            value[1] += max(tmp[0], tmp[1]);
        }
        if (root->right)
        {
            auto tmp = maxNode(root->right);
            value[0] += tmp[1];
            value[1] += max(tmp[0], tmp[1]);
        }
        return value;
    }

public:
    int rob(TreeNode *root)
    {
        auto tmp = maxNode(root);
        return max(tmp[0], tmp[1]);
    }
};

int main()
{
    return 0;
}