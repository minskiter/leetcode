#include "header.h"

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *dummy = new ListNode(0, head), *p = dummy;
        while (head != nullptr)
        {
            if (head->next != nullptr && head->val == head->next->val)
            {
                ListNode *temp = head;
                head = head->next;
                delete temp;
                p->next = head;
            }
            else
            {
                head = head->next;
                p = p->next;
            }
        }
        p = dummy->next;
        delete dummy;
        return p;
    }
};

int main()
{
    vector<int> temp = {1, 1, 2, 3, 3};
    ListNode *p = new ListNode(0);
    p->Parse(temp);
    Solution s;
    p = s.deleteDuplicates(p);
    p->Print();
    return 0;
}