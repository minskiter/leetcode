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
class Solution
{
    vector<int> _edges, _nxt, _head;
    void addEdges(vector<int> &edge)
    {
        _edges.emplace_back(edge[1]);
        _nxt.emplace_back(_head[edge[0]]);
        _head[edge[0]] = _nxt.size() - 1;
        _edges.emplace_back(edge[0]);
        _nxt.emplace_back(_head[edge[1]]);
        _head[edge[1]] = _nxt.size() - 1;
    }

public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n==1) return vector<int>{0};
        _head.resize(n);
        fill(_head.begin(), _head.end(), -1);
        vector<int> deg(n);
        for (int i = 0; i < edges.size(); ++i)
        {
            deg[edges[i][0]]++;
            deg[edges[i][1]]++;
            addEdges(edges[i]);
        }
        vector<vector<int>> s(2);
        for (int i = 0; i < deg.size(); ++i)
            if (deg[i] == 1)
                s[0].emplace_back(i);
        while (n > 2)
        {
            n -= s[0].size();
            while (!s[0].empty())
            {
                for (int p = _head[s[0].back()]; p >= 0; p = _nxt[p])
                    if (deg[_edges[p]] > 1)
                        s[1].emplace_back(_edges[p]);
                s[0].pop_back();
            }
            while (!s[1].empty())
            {
                --deg[s[1].back()];
                if (deg[s[1].back()] == 1)
                {
                    s[0].emplace_back(s[1].back());
                }
                s[1].pop_back();
            }
        }
        return s[0];
    }
};

int main()
{
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {1, 3}, {2, 4}, {3, 5}, {4, 6}};
    cout << Solution().findMinHeightTrees(7, edges);
    return 0;
}