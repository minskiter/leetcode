// 117同
#include "header.h"

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == nullptr)
            return root;
        queue<pair<Node *, int>> q;
        q.push(make_pair(root, 0));
        pair<Node *, int> last, p;
        bool first = true;
        while (!q.empty())
        {
            p = q.front();
            q.pop();
            if (!first)
            {
                if (last.second == p.second)
                {
                    last.first->next = p.first;
                }
            }
            else
            {
                first = false;
            }
            if (p.first->left)
            {
                q.push(make_pair(p.first->left, p.second + 1));
            }
            if (p.first->right)
            {
                q.push(make_pair(p.first->right, p.second + 1));
            }
            last = p;
        }
        return root;
    }
};

int main()
{
    return 0;
}