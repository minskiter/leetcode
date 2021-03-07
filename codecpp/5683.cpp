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
public:
    vector<int> countPairs(int n, vector<vector<int>> &edges, vector<int> &queries)
    {
        vector<int> indeg(n + 1);
        unordered_map<long long, int> diff;
        long long key;
        for (int i = 0; i < edges.size(); ++i)
        {
            if (edges[i][0] > edges[i][1])
                swap(edges[i][0], edges[i][1]);
            indeg[edges[i][0]]++;
            indeg[edges[i][1]]++;
            key = edges[i][0] * 100000LL + edges[i][1];
            if (diff.find(key) == diff.end())
                diff[key] = 1;
            else
                diff[key]++;
        }
        vector<int> sortdeg(indeg);
        sort(sortdeg.begin(), sortdeg.end());
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); ++i)
        {
            int r = n;
            for (int l = 1; l < n; ++l)
            {
                r = max(r, l + 1);
                while (l < r && sortdeg[l] + sortdeg[r] > queries[i])
                    --r;
                ans[i] += n - r;
            }
            for (auto [key, value] : diff)
            {
                auto u = key / 100000LL, v = key % 100000LL;
                if (indeg[u] + indeg[v] > queries[i] && indeg[u] + indeg[v] - value <= queries[i])
                    --ans[i];
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}