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
class AllOne
{
    unordered_map<string, int> cnt;
    list<unordered_set<string>> l;
    unordered_map<int, list<unordered_set<string>>::iterator> loca;

public:
    /** Initialize your data structure here. */
    AllOne()
    {
    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key)
    {
        if (cnt.find(key) == cnt.end())
        {
            cnt[key] = 1;
            if (l.empty())
            {
                l.push_back(unordered_set<string>{key});
                loca[1] = l.begin();
            }
            else
            {
                if (loca.find(1) == loca.end())
                {
                    l.push_back(unordered_set<string>{key});
                    loca[1] = prev(l.end());
                }
                else
                {
                    loca[1]->emplace(key);
                }
            }
        }
        else
        {
            cnt[key]++;
            // cout << key << " " <<  cnt[key] << endl;
            auto cur = loca[cnt[key]-1];
            cur->erase(key);  
            if (cur == l.begin())
            {
                l.push_front(unordered_set<string>{key});
                loca[cnt[key]] = l.begin();
            }
            else
            {
                auto pre = prev(cur);
                if (cnt[*(pre->begin())] == cnt[key])
                {
                    pre->emplace(key);
                }
                else
                {
                    loca[cnt[key]] = l.insert(cur, unordered_set<string>{key});
                }
            }
            if (cur->empty())
            {
                l.erase(cur);
                loca.erase(cnt[key]-1);
            }
        }
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key)
    {
        if (cnt.find(key) != cnt.end())
        {
            cnt[key]--;
            auto cur = loca[cnt[key] + 1];
            cur->erase(key);
            if (cnt[key] != 0)
            {
                auto nxt = next(cur);
                if (nxt == l.end())
                {
                    l.push_back(unordered_set<string>{key});
                    loca[cnt[key]] = prev(l.end());
                }
                else
                {
                    if (cnt[*(nxt->begin())] == cnt[key])
                    {
                        nxt->emplace(key);
                    }
                    else
                    {
                        loca[cnt[key]] = l.insert(nxt, unordered_set<string>{key});
                    }
                }
            }
            if (cur->empty())
            {
                l.erase(cur);
                loca.erase(cnt[key]+1);
            }
            if (cnt[key]==0){
                cnt.erase(key);
            }
        }
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey()
    {
        if (l.empty())
        {
            return "";
        }
        else
        {
            return *(l.front().begin());
        }
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey()
    {
        if (l.empty())
        {
            return "";
        }
        else
        {
            return *(l.back().begin());
        }
    }
};

int main()
{
    return 0;
}