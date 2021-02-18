#include "header.h"

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr)
            return false;
        ListNode *p = head->next;
        while (p != nullptr && p != head)
        {
            for (int i = 0; i < 2 && p != nullptr; ++i)
                p = p->next;
            head = head->next;
        }
        return p != nullptr;
    }
};

int main()
{
    return 0;
}