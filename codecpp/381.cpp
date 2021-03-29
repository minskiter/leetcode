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
class RandomizedCollection
{

    multimap<int, int> _map;
    vector<int> _vec;

public:
    /** Initialize your data structure here. */
    RandomizedCollection()
    {
    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val)
    {
        bool found = true;
        if (_map.find(val) != _map.end())
            found = false;
        _vec.push_back(val);
        _map.emplace(val, _vec.size() - 1);
        return found;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val)
    {
        bool found = true;
        auto itor = _map.find(val);
        if (itor != _map.end())
            found = false;
        if (found)
        {
            auto swapitor = _map.find(_vec[_vec.size() - 1]);
            while (swapitor->second !=_vec.size()-1) swapitor=next(swapitor);
            _vec[itor->second] = _vec[swapitor->second];
            _vec.pop_back();
            _map.emplace(swapitor->first, itor->second);
            _map.erase(swapitor);
            _map.erase(itor);
        }
    }

    /** Get a random element from the collection. */
    int getRandom()
    {
        return _vec[rand() % _vec.size()];
    }
};

int main()
{
    return 0;
}