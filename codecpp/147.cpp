#include "header.h"

class Solution
{
public:
    ListNode *insertionSortList(ListNode *head)
    {
        if (head==nullptr) return head;
        ListNode *dummy = new ListNode(0, head), *select = head->next, *nextEmplace, *temp;
        head->next = nullptr;
        while (select != nullptr)
        {
            nextEmplace = dummy;
            temp = select->next;
            while (nextEmplace)
            {
                if (nextEmplace->next==nullptr || select->val <= nextEmplace->next->val)
                {
                    select->next = nextEmplace->next;
                    nextEmplace->next = select;
                    break;
                }
                nextEmplace = nextEmplace->next;
            }
            select = temp;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};

int main()
{
    vector<int> nums = {-1, 5, 3, 4, 0};
    Solution s;
    ListNode *list = new ListNode();
    list->Parse(nums);
    s.insertionSortList(list)->Print();
    return 0;
}