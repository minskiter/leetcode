#include "header.h"

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *p = dummy->next;
        int len = 0;
        for (; p != nullptr; p = p->next)
        {
            ++len;
        }
        if (len==0) return head;
        k = k % len;
        reverse(dummy, len - k);
        p = dummy;
        for (int i = 0; i < len - k; ++i)
        {
            p = p->next;
        }
        reverse(p, k);
        reverse(dummy, len);
        head = dummy->next;
        delete dummy;
        return head;
    }

private:
    void reverse(ListNode *dummy, int k)
    {
        if (k == 0)
            return;
        ListNode *cur = dummy->next;
        ListNode *pre = dummy;
        int left = k;
        while (left != 0)
        {
            ListNode *temp = cur;
            cur = cur->next;
            temp->next = pre;
            pre = temp;
            left--;
        }
        dummy->next->next = cur;
        dummy->next = pre;
    }
};

int main()
{
    vector<int> temp = {};
    ListNode *temp2 = new ListNode();
    temp2->Parse(temp);
    Solution s;
    temp2 = s.rotateRight(nullptr, 0);
    temp2->Print();
    return 0;
}