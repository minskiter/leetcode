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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode * head=nullptr;
        ListNode * p=nullptr;
        while (l1!=nullptr || l2!=nullptr){
            if (head==nullptr){
                head=new ListNode();
                p=head;
            }else{
                p->next = new ListNode();
                p=p->next;
            }
            if (l2==nullptr || (l1!=nullptr && l1->val<l2->val)){
                p->val = l1->val;
                l1=l1->next;
            }else{
                p->val = l2->val;
                l2=l2->next;
            }
        }
        return head;
    }
};

int main()
{
    Solution s;
    vector<int> l1={};
    vector<int> l2={0};
    ListNode * l3=new ListNode(),*l4= new ListNode();
    l3->Parse(l1);
    l4->Parse(l2);
    s.mergeTwoLists(nullptr,l4)->Print();
    return 0;
}