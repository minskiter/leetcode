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
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> x;
        unordered_map<string, char> y;
        string buffer;
        buffer.reserve(s.size());
        s.append(" ");
        int l = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == ' ')
            {
                if (x.find(pattern[l]) != x.end())
                {
                    if (x[pattern[l]] != buffer)
                        return false;
                    if (y[buffer] != pattern[l])
                        return false;
                }
                else if (y.find(buffer) != y.end())
                    return false;
                x[pattern[l]] = buffer;
                y[buffer] = pattern[l++];
                buffer.resize(0);
            }
            else
                buffer += s[i];
        }
        return l == pattern.size();
    }
};

int main()
{
    return 0;
}