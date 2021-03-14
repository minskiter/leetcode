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
    string removeDuplicateLetters(string s)
    {
        string st;
        vector<int> vis(26);
        vector<int> cnt(s.size());
        for (auto index = (int)s.size() - 1; index >= 0; --index)
        {
            vis[s[index] - 'a']++;
            cnt[index] = vis[s[index] - 'a'];
        }
        fill(vis.begin(), vis.end(), 0);
        for (int index = 0; index < s.size(); ++index)
        {
            if (vis[s[index] - 'a'] > 0)
                continue;
            while (!st.empty() && st[st.size() - 1] > s[index])
            {
                bool contains=false;
                for (int i=index;i<s.size();++i){
                    if (s[i]==st[st.size()-1]) contains=true;
                }
                if (!contains) break;
                vis[st[st.size() - 1] - 'a']--;
                st.pop_back();
            }
            st.push_back(s[index]);
            vis[s[index] - 'a']++;
        }
        return st;
    }
};

int main()
{
    cout << Solution().removeDuplicateLetters("bcabc");
    return 0;
}