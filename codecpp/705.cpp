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
class MyHashSet
{
    const int size = 10013;
    vector<list<int>> s = vector<list<int>>(size);

public:
    /** Initialize your data structure here. */
    MyHashSet()
    {
    }

    void add(int key)
    {
        int hash = key % size;
        if (!contains(key))
            s[hash].push_back(key);
    }

    void remove(int key)
    {
        int hash = key % size;
        for (auto itor = s[hash].begin(); itor != s[hash].end(); itor = next(itor))
        {
            if (*itor == key)
            {
                s[hash].erase(itor);
                return;
            }
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        int hash = key % size;
        for (auto item:s[hash])
            if (item == key)
                return true;
        return false;
    }
};

int main()
{
    return 0;
}