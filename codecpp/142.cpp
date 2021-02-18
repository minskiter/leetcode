#include "header.h"

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fast = head, *slow = head;
        while (fast)
        {
            fast = fast->next ? fast->next->next : nullptr;
            slow = slow->next;
            if (fast == slow)
                break;
        }
        if (!fast)
            return nullptr;
        while (head != slow)
        {
            head = head->next;
            slow = slow->next;
        }
        return head;
    }
};

int main()
{

    return 0;
}