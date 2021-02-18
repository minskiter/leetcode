#include "header.h"

struct hashfunc
{
    template <typename T, typename U>
    size_t operator()(const pair<T, U> &x) const
    {
        return hash<T>()(x.first) ^ hash<U>()(x.second);
    }
};

class Solution
{
private:
    int gcd(int a, int b)
    {
        while (b ^= a ^= b ^= a %= b)
            ;
        return a;
    }
    pair<int, int> getK(int x, int y, int x1, int y1)
    {
        int dx = abs(x1 - x);
        int dy = abs(y1 - y);
        if (dx == 0)
        {
            return make_pair(INT_MIN, INT_MAX);
        }
        else if (dy == 0)
        {
            return make_pair(0, 0);
        }
        int g = gcd(dx, dy);
        dx /= g;
        dy /= g;
        return make_pair(y1 > y ? dy : -dy, x1 > x ? dx : -dx);
    }

public:
    int maxPoints(vector<vector<int>> &points)
    {
        int maxinum = min<int>(points.size(), 1);
        unordered_map<pair<int, int>, int, hashfunc> k;
        for (int i = 0; i < points.size(); ++i)
        {
            k.clear();
            int same_points = 0;
            for (int j = 0; j < points.size(); ++j)
            {
                if (i==j || points[i][0] == points[j][0] && points[i][1] == points[j][1])
                {
                    ++same_points;
                }
            }
            maxinum = max(same_points, maxinum);
            for (int j = 0; j < points.size(); ++j)
            {
                if (i == j || (points[i][0] == points[j][0] && points[i][1] == points[j][1]))
                    continue;
                auto ki = getK(points[i][0], points[i][1], points[j][0], points[j][1]);
                if (k.find(ki) == k.end())
                {
                    k[ki] = same_points + 1;
                }
                else
                {
                    k[ki]++;
                }
                maxinum = max(k[ki], maxinum);
            }
        }
        return maxinum;
    }
};

int main()
{
    vector<vector<int>> points = {{1, 1}, {1, 1}, {1, 2}};
    Solution s;
    cout << s.maxPoints(points);
    return 0;
}