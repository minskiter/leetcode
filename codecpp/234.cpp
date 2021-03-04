#include "header.h"

#define rep(i, f, t, s) for (int i = f; i <= (int)t; i += s)
#define repd(i, f, t, s) for (int i = f; i >= (int)t; i -= s)
#define mk(a, b) make_pair(a, b)
#define sqr(a) ((a) * (a))
template <class Ty1, class Ty2>
inline const pair<Ty1, Ty2> operator+(const pair<Ty1, Ty2> &p1, const pair<Ty1, Ty2> &p2)
{
    return mk(p1.first + p2.first, p1.second + p2.second);
}
template <class Ty1, class Ty2>
inline const pair<Ty1, Ty2> operator-(const pair<Ty1, Ty2> &p1, const pair<Ty1, Ty2> &p2)
{
    return mk(p1.first - p2.first, p1.second - p2.second);
}
template <class Ty1, class Ty2>
bool inner(pair<Ty1, Ty2> pos, pair<Ty1, Ty2> leftTop, pair<Ty1, Ty2> rightBottom)
{
    if (pos.first >= leftTop.first && pos.second >= leftTop.second)
    {
        if (pos.first < rightBottom.first && pos.second < rightBottom.second)
        {
            return true;
        }
    }
    return false;
}

// Solution Here
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        // Get Middle Itor
        ListNode *fast = head, *slow = head;
        while (fast->next)
        {
            fast = fast->next;
            if (fast->next)
                fast = fast->next;
            slow = slow->next;
        }
        // Reverse half list
        ListNode *dummy = new ListNode(0);
        fast = slow;
        while (fast)
        {
            auto tmp = fast->next;
            fast->next = dummy->next;
            dummy->next = fast;
            fast = tmp;
        }
        slow = dummy->next, fast = head;
        auto ans = true;
        while (slow)
        {
            if (slow->val != fast->val)
            {
                ans = false;
                break;
            }
            slow = slow->next;
            fast = fast->next;
        }
        // Recover List
        fast = dummy->next;
        dummy->next = nullptr;
        while (fast->next)
        {
            auto tmp = fast->next;
            fast->next = dummy->next;
            dummy->next = fast;
            fast = tmp;
        }
        delete dummy;
        return ans;
    }
};

int main()
{
    vector<int> list = {1, 2};
    ListNode *node = (new ListNode())->Parse(list);
    cout << Solution().isPalindrome(node);
    return 0;
}