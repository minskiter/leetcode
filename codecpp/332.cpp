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

bool cmp(pair<string, int> &a, pair<string, int> &b)
{
    return a.first < b.first;
}

// Solution Here
class Solution
{
public:
    vector<int> head, edges, nxt;
    unordered_map<string, int> one_hot;
    vector<string> origin;
    string minAns;

    void addEdge(int f, int t)
    {
        edges.emplace_back(t);
        nxt.emplace_back(head[f]);
        head[f] = edges.size() - 1;
    }
    bool dfs(vector<string> &ans, vector<bool> &visEdge, int location, int total)
    {
        if (ans.size() == total)
            return true;
        vector<pair<string, int>> edge;
        int p = head[location];
        while (p != -1)
        {
            if (!visEdge[p])
            {
                edge.emplace_back(mk(origin[edges[p]], p));
            }
            p = nxt[p];
        }
        sort(edge.begin(), edge.end(), cmp);
        for (auto e : edge)
        {
            visEdge[e.second] = true;
            ans.emplace_back(e.first);
            if (dfs(ans, visEdge, one_hot[e.first], total))
                return true;
            ans.pop_back();
            visEdge[e.second] = false;
        }
        return false;
    }
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        for (int i = 0; i < tickets.size(); ++i)
        {
            int f, t;
            if (one_hot.find(tickets[i][0]) == one_hot.end())
            {
                head.emplace_back(-1);
                origin.emplace_back(tickets[i][0]);
                one_hot[tickets[i][0]] = head.size() - 1;
                f = head.size() - 1;
            }
            else
            {
                f = one_hot[tickets[i][0]];
            }
            if (one_hot.find(tickets[i][1]) == one_hot.end())
            {
                head.emplace_back(-1);
                origin.emplace_back(tickets[i][1]);
                one_hot[tickets[i][1]] = head.size() - 1;
                t = head.size() - 1;
            }
            else
            {
                t = one_hot[tickets[i][1]];
            }
            addEdge(f, t);
        }
        vector<bool> visEdge(edges.size());
        vector<string> ans{"JFK"};
        dfs(ans, visEdge, one_hot["JFK"], edges.size()+1);
        return ans;
    }
};

int main()
{
    return 0;
}