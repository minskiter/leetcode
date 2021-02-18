#define RandomNode
#include "header.h"

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> cloneNode;
        for (auto p = head; p != nullptr; p = p->next)
        {
            cloneNode[p] = new Node(p->val);
        }
        for (auto p = head; p != nullptr; p = p->next)
        {
            if (p->next != nullptr)
                cloneNode[p]->next = cloneNode[p->next];
            if (p->random != nullptr)
                cloneNode[p]->random = cloneNode[p->random];
        }
        return head==nullptr?nullptr:cloneNode[head];
    }
};

int main()
{
    return 0;
}