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
    void kmp(string &a, string &b, unordered_set<int> &ans, const int &pos, unordered_map<string, vector<int>> &wordList, bool reflag = false)
    {
        vector<int> pre(a.size(), -1);
        int j = -1;
        for (int k = 1; k < a.size(); ++k)
        {
            while (j != -1 && a[j + 1] != a[k])
                j = pre[j];
            if (a[j + 1] == a[k])
                ++j;
            pre[k] = j;
        }
        j = -1;
        for (int k = 0; k < b.size(); ++k)
        {
            while (j != -1 && a[j + 1] != b[k])
                j = pre[j];
            if (a[j + 1] == b[k])
                ++j;
            if (k == b.size() - 1)
            {
                while (true)
                {
                    string tmp;
                    if (!reflag)
                        tmp = a.substr(j + 1, a.size() - j - 1);
                    else
                        tmp = b.substr(0, k - j);
                    if (wordList.find(tmp) != wordList.end())
                    {
                        auto ptr = &wordList[tmp];
                        for (int i = 0; i < ptr->size(); ++i)
                        {
                            if ((*ptr)[i] != pos)
                            {
                                if (!reflag)
                                {
                                    ans.insert(pos * 5001 + (*ptr)[i]);
                                }
                                else
                                {
                                    ans.insert(((*ptr)[i] * 5001) + pos);
                                }
                            }
                        }
                    }
                    if (j == -1)
                        break;
                    j = pre[j];
                }
            }
        }
    }

public:
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        unordered_map<string, vector<int>> wordList;
        for (int i = 0; i < words.size(); ++i)
        {
            if (wordList.find(words[i]) == wordList.end())
                wordList[words[i]] = vector<int>{i};
            else
                wordList[words[i]].emplace_back(i);
        }
        unordered_set<int> ansSet;
        for (int i = 0; i < words.size(); ++i)
        {
            if (words[i].size() == 0)
                continue;
            auto re = words[i];
            reverse(re.begin(), re.end());
            kmp(re, words[i], ansSet, i, wordList);
            kmp(words[i], re, ansSet, i, wordList, true);
        }
        vector<vector<int>> ans;
        for (auto item : ansSet)
        {
            vector<int> tmp = {item / 5001, item % 5001};
            ans.emplace_back(tmp);
        }
        return ans;
    }
};

int main()
{
    return 0;
}


