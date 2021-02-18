#include "header.h"

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next) return head;
        int size, len = 0;
        for (auto p = head; p; p = p->next)
            ++len;
        ListNode dummy(0, head);
        ListNode *first = head, *second = head, *tail = head, *last = tail, *pre = &dummy;
        for (size = 1; size <= len; size <<= 1)
        {
            while (last)
            {
                for (int i = 1; i < size && second; ++i, second = second->next)
                    ;
                if (!second)
                    break;
                tail = second->next;
                second->next = nullptr;
                second = tail;
                if (!second)
                    break;
                for (int i = 1; i < size && tail && tail->next; ++i, tail = tail->next)
                    ;
                last = tail->next;
                tail->next = nullptr;
                pre->next = mergeSortList(first, second, tail);
                tail->next = last;
                pre = tail;
                first = second = tail = last;
            }
            first = second = tail = last = dummy.next;
            pre = &dummy;
        }
        return dummy.next;
    }

private:
    ListNode *mergeSortList(ListNode *first, ListNode *second, ListNode *&tail)
    {
        if (first == nullptr)
        {
            for (tail = first; tail && tail->next; tail = tail->next)
                ;
            return second;
        }
        if (second == nullptr)
        {
            for (tail = first; tail && tail->next; tail = tail->next)
                ;
            return first;
        }
        ListNode dummy(0, nullptr);
        tail = &dummy;
        while (first != nullptr && second != nullptr)
        {
            if (first->val <= second->val)
            {
                tail->next = first;
                first = first->next;
            }
            else
            {
                tail->next = second;
                second = second->next;
            }
            tail = tail->next;
        }
        if (first != nullptr)
            tail->next = first;
        if (second != nullptr)
            tail->next = second;
        if (!first && !second)
            tail->next = nullptr;
        while (tail->next)
            tail = tail->next;
        return dummy.next;
    }
};

int main()
{
    vector<int> nodes = {5};
    ListNode *head = new ListNode();
    head->Parse(nodes);
    Solution s;
    s.sortList(head)->Print();
    return 0;
}