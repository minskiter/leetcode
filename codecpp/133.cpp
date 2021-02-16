#define NeighborNode
#include "header.h"

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (node == nullptr)
            return nullptr;
        Node *cloneMap[101] = {nullptr};
        return clonePoint(node, cloneMap);
    }

private:
    Node *clonePoint(Node *node, Node *cloneMap[])
    {
        auto cloneNode = new Node(node->val);
        cloneMap[node->val] = cloneNode;
        for (int i = 0; i < node->neighbors.size(); ++i)
        {
            if (cloneMap[node->neighbors[i]->val])
                cloneNode->neighbors.push_back(cloneMap[node->neighbors[i]->val]);
            else
                cloneNode->neighbors.push_back(clonePoint(node->neighbors[i], cloneMap));
        }
        return cloneNode;
    }
};

int main()
{
    vector<vector<int>> test = {{2, 4}, {1, 3}, {2, 4}, {1, 3}};
    Solution s;
    Node *node = new Node();
    node->Parse(test);
    node->Print();
    s.cloneGraph(node)->Print();
    return 0;
}
