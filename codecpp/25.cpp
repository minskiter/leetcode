#include "header.h"

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        vector<ListNode *> buffer(k);
        ListNode *dummy = new ListNode(0, head), *p = head;
        head=dummy;
        while (p!=nullptr){
            for (int i=0;i<k;++i,p=p->next){
                if (p==nullptr){
                    p=dummy->next;
                    delete dummy;
                    return p;
                }
                buffer[i]=p;
            }
            buffer[0]->next = buffer[k-1]->next;
            for (int i=k-1;i>0;--i){
                buffer[i]->next=buffer[i-1];
            }
            head->next = buffer[k-1];
            head = buffer[0];
        }
        p = dummy->next;
        delete dummy;
        return p;
    }
};

int main()
{
    Solution s;
    vector<int> data = {1,2,3,4,5,6};
    ListNode *test= new ListNode();
    test->Parse(data);
    s.reverseKGroup(test,3)->Print();
    return 0;
}