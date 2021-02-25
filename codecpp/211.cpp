#include "header.h"

#define rep(i, f, t, s) for (int i = f; i <= t; i += s)
#define repd(i, f, t, s) for (int i = f; i >= t; i -= s)
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

struct Tree
{
    bool word;
    Tree *sub[26];
    Tree() : word(false)
    {
        fill(sub, sub + 26, nullptr);
    }
};

// Solution Here
class WordDictionary
{
    Tree *root;

public:
    /** Initialize your data structure here. */
    WordDictionary()
    {
        root = new Tree();
    }

    void addWord(string word)
    {
        auto p = root;
        for (int i = 0; i < word.size(); ++i)
        {
            if (p->sub[word[i] - 'a']==nullptr)
            {
                p->sub[word[i] - 'a'] = new Tree();
            }
            p = p->sub[word[i] - 'a'];
        }
        p->word = true;
    }

    bool search(string word)
    {
        stack<pair<Tree *,int>> s;
        pair<Tree *,int> p;
        s.emplace(root,-1);
        while (!s.empty()){
            p = s.top();
            s.pop();
            if (p.second+1>=word.size()){
                if (p.first->word){
                    return true;
                }
                continue;
            }
            if (word[p.second+1]=='.'){
                for (int i=0;i<26;++i){
                    if (p.first->sub[i]){
                        s.emplace(p.first->sub[i],p.second+1);
                    }
                }
            }else{
                if (p.first->sub[word[p.second+1]-'a']){
                    s.emplace(p.first->sub[word[p.second+1]-'a'],p.second+1);
                }
            }       
        }
        return false;
    }
};

int main()
{
    WordDictionary wordDictionary;
    wordDictionary.addWord("bad");
    wordDictionary.addWord("dad");
    wordDictionary.addWord("mad");
    cout << wordDictionary.search("pad"); // return False
    cout << wordDictionary.search("bad"); // return True
    cout << wordDictionary.search(".ad"); // return True
    cout << wordDictionary.search("b.."); // return True
    return 0;
}