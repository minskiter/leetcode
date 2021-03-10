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
class MedianFinder
{
    priority_queue<int> maxq;
    priority_queue<int, vector<int>, greater<int>> minq;

public:
    /** initialize your data structure here. */
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (minq.size() == 0)
        {
            minq.emplace(num);
        }
        else if (maxq.size() == 0)
        {
            maxq.emplace(num);
        }
        else
        {
            if (minq.size() <= maxq.size())
                minq.emplace(num);
            else
                maxq.emplace(num);     
            while (minq.top() < maxq.top())
            {
                auto tmp = maxq.top();
                maxq.pop();
                maxq.emplace(minq.top());
                minq.pop();
                minq.emplace(tmp);
            }
        }
    }

    double findMedian()
    {
        if (minq.size() == maxq.size())
            return (minq.top() + maxq.top()) / 2.0;
        else
            return minq.top();
    }
};

int main()
{
    return 0;
}