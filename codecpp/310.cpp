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
        _head.resize(n);
        fill(_head.begin(), _head.end(), -1);
        for (int i = 0; i < edges.size(); ++i)
            addEdges(edges[i]);
        vector<int> heights(n);
        vector<bool> vis(n, false);
        vis[0] = true;
        search_init(heights, vis, 0);
        vector<int> ans{};
        int minHeight = heights[0];
        vis[0] = false;
        search_min_height(ans, minHeight, 0, vis, heights);
        return ans;
    }

    void search_init(vector<int> &heights, vector<bool> &vis, int root)
    {
        auto p = _head[root];
        heights[root] = 1;
        while (p != -1)
        {
            if (!vis[_edges[p]])
            {
                vis[_edges[p]] = true;
                search_init(heights, vis, _edges[p]);
                heights[root] = max(heights[root], heights[_edges[p]] + 1);
            }
            p = _nxt[p];
        }
    }

    void search_min_height(vector<int> &ans, int &minHeight, int root, vector<bool> &vis, vector<int> &heights)
    {
        int origin = heights[root];
        int firstHeight = 0, secondHeight = 0, p = _head[root];
        while (p != -1)
        {
            if (heights[_edges[p]] > firstHeight)
            {
                secondHeight = firstHeight;
                firstHeight = heights[_edges[p]];
            }
            else if (heights[_edges[p]] > secondHeight)
            {
                secondHeight = heights[_edges[p]];
            }
            p = _nxt[p];
        }
        heights[root] = firstHeight + 1;
        if (heights[root] < minHeight)
        {
            minHeight = heights[root];
            ans.clear();
            ans.emplace_back(root);
        }
        else if (heights[root] == minHeight)
        {
            ans.emplace_back(root);
        }
        // move next root
        p = _head[root];
        while (p != -1)
        {
            if (vis[_edges[p]])
            {
                vis[_edges[p]] = false;
                if (heights[_edges[p]] != firstHeight)
                    heights[root] = firstHeight + 1;
                else
                    heights[root] = secondHeight + 1;
                search_min_height(ans, minHeight, _edges[p], vis, heights);
            }
            p = _nxt[p];
        }
        heights[root] = origin;
    }
};

int main()
{
    vector<vector<int>> edges = {{0,1},{1,2},{1,3},{2,4},{3,5},{4,6}};
    cout << Solution().findMinHeightTrees(7, edges);
    return 0;
}