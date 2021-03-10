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
class Codec
{
public:
    static string encode(TreeNode *node)
    {
        int val = node == nullptr ? 1001 : node->val;
        return "" + char(val / 256 - 128) + char(val % 256 - 128);
    }
    static TreeNode *decode(char high, char low)
    {
        int val = (high + 128) * 256 + low + 128;
        if (val == 1001)
            return nullptr;
        return new TreeNode(val);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.emplace(root);
        string buffer;
        while (!q.empty())
        {
            auto tmp = q.front();
            q.pop();
            buffer.append(encode(tmp));
            if (tmp != nullptr)
            {
                q.emplace(tmp->left);
                q.emplace(tmp->right);
            }
        }
        return buffer;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.size() == 0)
            return nullptr;
        queue<TreeNode *> q;
        auto root = decode(data[0], data[1]);
        if (root == nullptr)
            return root;
        q.emplace(root);
        for (int i = 2; i < data.size(); i += 4)
        {
            auto front = q.front();
            q.pop();
            front->left = decode(data[i], data[i + 1]);
            front->right = decode(data[i + 2], data[i + 3]);
            if (front->left)
                q.emplace(front->left);
            if (front->right)
                q.emplace(front->right);
        }
        return root;
    }
};

int main()
{
    return 0;
}