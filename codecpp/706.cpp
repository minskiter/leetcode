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
class MyHashMap
{
    const int size = 10013;
    vector<list<pair<int, int>>> data = vector<list<pair<int, int>>>(size);

public:
    /** Initialize your data structure here. */
    MyHashMap()
    {
    }

    /** value will always be non-negative. */
    void put(int key, int value)
    {
        int hash = key % size;
        bool isEdit = false;
        for (auto &itor : data[hash])
        {
            if (itor.first == key)
            {
                itor.second = value;
                isEdit = true;
                break;
            }
        }
        if (!isEdit)
        {
            data[hash].push_back(mk(key, value));
        }
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key)
    {
        int hash = key % size;
        for (auto &itor : data[hash])
        {
            if (itor.first == key)
            {
                return itor.second;
            }
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key)
    {
        int hash = key % size;
        for (auto itor = data[hash].begin(); itor != data[hash].end(); itor = next(itor))
        {
            if (itor->first==key){
                data[hash].erase(itor);
                break;
            }
        }
    }
};

int main()
{
    return 0;
}