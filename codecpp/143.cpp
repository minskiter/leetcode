#include "header.h"

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (head==nullptr || head->next==nullptr) return;
        ListNode *fast = head, *slow = head;
        while (fast && fast->next)
        {
            fast = fast->next ? fast->next->next : nullptr;
            slow = slow->next;
        }
        fast = slow;
        ListNode *nxt = fast->next, *last = nxt;
        while (nxt)
        {
            fast = nxt;
            nxt = nxt->next;
            fast->next = slow->next;
            slow->next = fast;
        }
        if (last)
            last->next = nullptr;
        fast = slow;
        nxt = fast->next;
        while (nxt)
        {
            fast = nxt;
            nxt = fast->next;
            fast->next = head->next;
            head->next = fast;
            head = fast->next;
        }
        slow->next = nullptr;
    }
};

int main()
{
    vector<int> a = {1,2};
    Solution s;
    ListNode *list = new ListNode();
    list->Parse(a);
    s.reorderList(list);
    list->Print();
    return 0;
}