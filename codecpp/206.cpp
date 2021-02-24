#include "header.h"

#define rep(i, f, t, s) for (int i = f; i <= t; i += s)
#define repd(i, f, t, s) for (int i = f; i >= t; i -= s)
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

// Solution Here
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *dummy = new ListNode(), *next = head, *temp;
        while (next)
        {
            temp = next->next;
            next->next = dummy->next;
            dummy->next = next;
            next = temp;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};

int main()
{
    return 0;
}