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

class NestedInteger
{
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};
// Solution Here
class NestedIterator
{
    vector<pair<vector<NestedInteger> *, int>> s;

public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        s.emplace_back(make_pair(&nestedList, -1));
    }

    int next()
    {
        ++s[s.size() - 1].second;
        return (*(s[s.size() - 1].first))[s[s.size() - 1].second].getInteger();
    }

    bool hasNext()
    {
        do
        {
            while (!s.empty() && s[s.size() - 1].second + 1 < s[s.size() - 1].first->size() && !(*(s[s.size() - 1].first))[s[s.size() - 1].second + 1].isInteger())
            {
                ++s[s.size() - 1].second;
                s.emplace_back(make_pair(&(*(s[s.size() - 1].first))[s[s.size() - 1].second].getList(), -1));
            }
            while (!s.empty())
            {
                if (s[s.size() - 1].second + 1 >= s[s.size() - 1].first->size())
                    s.pop_back();
                else
                    break;
            }
        } while (!s.empty() && s[s.size() - 1].second + 1 < s[s.size() - 1].first->size() && !(*(s[s.size() - 1].first))[s[s.size() - 1].second + 1].isInteger());
        return !s.empty();
    }
};

int main()
{
    return 0;
}