#include "header.h"

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        auto merge = [](ListNode *a, ListNode *b) {
            ListNode *head = nullptr, *p = nullptr;
            while (a != nullptr || b != nullptr)
            {
                int temp;
                if (b == nullptr || (a != nullptr && a->val < b->val))
                {
                    temp = a->val;
                    a = a->next;
                }
                else
                {
                    temp = b->val;
                    b = b->next;
                }
                p = head == nullptr ? head = new ListNode(temp) : p->next = new ListNode(temp);
            }
            return head;
        };
        int deepth = 0;
        for (int i = 1; i < lists.size() + 2; i <<= 1){
            deepth ++ ;
        }
        for (int k = 0,step = 2; k < deepth;++k,step <<= 1)
        {
            for (int i = 0; i < lists.size(); i += step)
            {
                int near = step >> 1;
                if (i + near < lists.size())
                    lists[i] = merge(lists[i], lists[i + near]);
            }
        }
        return lists.size() == 0 ? nullptr : lists[0];
    }
};

int main()
{
    vector<int> a = {};
    vector<int> b = {1, 3, 4};
    vector<int> c = {2, 6};
    ListNode *al = new ListNode();
    ListNode *bl = new ListNode();
    ListNode *cl = new ListNode();
    al->Parse(a);
    bl->Parse(b);
    cl->Parse(c);
    vector<ListNode *> temp = {};
    Solution s;
    al = s.mergeKLists(temp);
    if (al != nullptr)
        al->Print();
    return 0;
}