#include "header.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode * guard = new ListNode(0,head),* p = guard;
        while (p->next!=nullptr){
            if (p->next->next!=nullptr){
                ListNode * temp = p->next;
                p->next = temp->next;
                temp->next = p->next->next;
                p->next->next = temp;
                p=p->next->next;
            }else{
                p=p->next;
            }
        }
        p=guard->next;
        delete guard;
        return p;
    }
};

int main(){
    vector<int> a = {1};
    ListNode * temp = new ListNode();
    temp->Parse(a);
    Solution s;
    s.swapPairs(temp)->Print();
    return 0;
}