#include "header.h"

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *p1 = headA, *p2 = headB;
        int size1, size2;
        for (size1 = 0; p1; p1 = p1->next)
            ;
        for (size2 = 0; p2; p2 = p2->next)
            ;
        p1 = headA;
        p2 = headB;
        if (size2 > size1)
            for (int i = 0; i < size2 - size1; ++i, p2 = p2->next)
                ;
        else
            for (int i = 0; i < size1 - size2; ++i, p1 = p1->next)
                ;
        while (p2 && p1 && p2 != p1)
        {
            p2 = p2->next;
            p1 = p1->next;
        }
        return p1 ? p1 : nullptr;
    }
};

int main()
{
    return 0;
}