#include "header.h"

#define rep(i, f, t, s) for (int i = f; i <= (int)t; i += s)
#define repd(i, f, t, s) for (int i = f; i >= (int)t; i -= s)
#define mk(a,b) make_pair(a,b)
#define sqr(a) ((a) * (a))
template<class Ty1,class Ty2> 
inline const pair<Ty1,Ty2> operator+(const pair<Ty1, Ty2>&p1, const pair<Ty1, Ty2>&p2)
{
    return mk(p1.first + p2.first,p1.second + p2.second);
}
template<class Ty1, class Ty2> 
inline const pair<Ty1, Ty2> operator-(const pair<Ty1, Ty2>&p1, const pair<Ty1, Ty2>&p2)
{
    return mk(p1.first - p2.first,p1.second - p2.second);
}
template <class Ty1, class Ty2>
bool inner(pair<Ty1,Ty2> pos,pair<Ty1,Ty2> leftTop,pair<Ty1,Ty2> rightBottom){
    if (pos.first>=leftTop.first && pos.second>=leftTop.second){
        if (pos.first<rightBottom.first && pos.second<rightBottom.second){
            return true;
        }
    }
    return false;
}

// Solution Here
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode * odd=new ListNode(),*even=new ListNode(),*ol=odd,*el=even;
        int cnt=1;
        while (head!=nullptr){
            if (cnt&1){
                ol->next = head;
                ol = ol->next;
            }else{
                el->next = head;
                el = el->next;
            }
            ++cnt;
            head=head->next;
        }
        ol->next = even->next;
        el->next = nullptr;
        head = odd->next;
        delete odd;
        delete even;
        return head;
    }
};

int main()
{
    return 0;
}