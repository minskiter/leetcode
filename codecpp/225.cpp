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
class MyStack
{
    int cur = 0;
    queue<int> q[2];

public:
    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        q[cur & 1].emplace(x);
        while (!q[(cur + 1) & 1].empty())
        {
            q[(cur + 1) & 1].emplace(q[cur & 1].front());
            q[cur & 1].pop();
        }
        cur = (cur + 1) & 1;
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        auto tmp = q[cur & 1].front();
        q[cur & 1].pop();
        return tmp;
    }

    /** Get the top element. */
    int top()
    {
        return q[cur & 1].front();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return q[cur & 1].empty() && q[(cur + 1) & 1].empty();
    }
};

int main()
{
    return 0;
}