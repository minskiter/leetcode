#include "header.h"

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        ListNode *dummy = new ListNode(0, head), *p = dummy;
        int i;
        for (i = 1; i < m; ++i)
        {
            head = head->next;
            p = p->next;
        }
        ListNode *mtail = p, *temp;
        for (i = m; i <= n; ++i)
        {
            temp = head;
            head = head->next;
            temp->next = p;
            p = temp;
        }
        if (mtail->next != nullptr)
            mtail->next->next = head;
        mtail->next = p;
        head = dummy->next;
        delete dummy;
        return head;
    }
};

int main()
{
    vector<int> nums={1,2,3,4,5};
    ListNode * list = new ListNode();
    list->Parse(nums);
    Solution s;
    s.reverseBetween(list,2,4)->Print();
    return 0;
}