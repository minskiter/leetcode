#include "header.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *dummy = new ListNode(0, head), *move = new ListNode(), *p = dummy, *temp, *moveTail = move;
        while (head != nullptr)
        {
            if (head->val < x)
            {
                temp = head;
                head = head->next;
                moveTail->next = temp;
                moveTail = moveTail->next;
                p->next = head;
            }
            else
            {
                p = p->next;
                head = head->next;
            }
        }
        moveTail->next = dummy->next;
        dummy->next = move->next;
        delete move;
        head = dummy->next;
        delete dummy;
        return head;
    }
};

int main()
{
    vector<int> head = {2,1};
    Solution s;
    ListNode *temp = new ListNode();
    temp->Parse(head);
    s.partition(temp,2)->Print();
    return 0;
}