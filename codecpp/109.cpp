#include "header.h"

class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        ListNode *p = head;
        int size;
        for (size = 0; p != nullptr; size++, p = p->next)
            ;
        return buildBST(head, size);
    }

private:
    TreeNode *buildBST(ListNode *head, int size)
    {
        if (size <= 0 || head == nullptr)
            return nullptr;
        if (size == 1)
        {
            return new TreeNode(head->val);
        }
        int mid = size >> 1;
        auto p = head;
        while (mid > 0)
        {
            p = p->next;
            --mid;
        }
        mid = size >> 1;
        auto node = new TreeNode(p->val);
        node->right = buildBST(p->next, size - mid - 1);
        node->left = buildBST(head, mid);
        return node;
    }
};

int main()
{
    vector<int> list = {-10, -3, 0, 5, 9};
    ListNode *listnode = new ListNode();
    listnode->Parse(list);
    Solution s;
    s.sortedListToBST(listnode)->PrintTree();
    return 0;
}