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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * fast=head;
        // Delete Slow Next
        ListNode * slow=head;
        for (int i=0;i<=n;++i){
            if (fast==nullptr){
                if (i==n){
                    slow = slow->next;
                    delete head;
                    return slow;
                }
                return head;
            }
            fast=fast->next;
        }
        while (fast){
            slow=slow->next;
            fast=fast->next;
        }
        fast = slow->next;
        slow->next = fast->next;
        delete fast;
        return head;
    }
};

int main(){
    Solution s;
    vector<int> a {1};
    ListNode * temp = new ListNode();
    temp->Parse(a);
    s.removeNthFromEnd(temp,2)->Print();
    return 0;
}