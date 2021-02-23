#include "header.h"

#define rep(i, f, t, s) for (int i = f; i <= t; i += s)
#define repd(i, f, t, s) for (int i = f; i >= t; i -= s)
#define mk(a, b) make_pair(a, b)

// Solution Here
class CQueue
{
    stack<int> s[2];

public:
    CQueue()
    {
    }

    void appendTail(int value)
    {
        s[0].emplace(value);
    }

    int deleteHead()
    {
        while (!s[0].empty())
        {
            s[1].emplace(s[0].top());
            s[0].pop();
        }
        if (s[1].empty())
            return -1;
        auto tmp = s[1].top();
        return tmp;
    }
};

int main()
{
    return 0;
}