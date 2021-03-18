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
private:
    bool isLess(vector<int> &distance, int start)
    {
        for (int i = start; i < distance.size(); ++i)
            if (distance[i] > distance[i - 2])
                return true;
        return false;
    }

public:
    bool isSelfCrossing(vector<int> &distance)
    {
        int great = false;
        for (int i = 2; i < distance.size(); ++i)
        {
            if (distance[i] > distance[i - 2])
                great = true;
            else if (great)
            {
                if (distance[i] == distance[i - 2])
                {
                    if (i + 1 >= distance.size())
                        return false;
                    if (distance[i + 1] >= distance[i - 1] - distance[i - 3])
                    {
                        return true;
                    }
                    return isLess(distance, i + 1);
                }
                if (i - 4 < 0)
                {
                    return isLess(distance, i + 1);
                }
                else if (i + 1 >= distance.size())
                {
                    return false;
                }
                else
                {
                    if (distance[i + 1] >= distance[i - 1] - distance[i - 3] && distance[i] >= distance[i - 2] - distance[i - 4])
                    {
                        return true;
                    }
                    return isLess(distance, i + 1);
                }
            }
            else
            {
                return isLess(distance, i);
            }
        }
        return false;
    }
};

int main()
{
    return 0;
}