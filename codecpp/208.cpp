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
class Trie
{
    Tree *root;

public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new Tree();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        auto p = root;
        for (int i = 0; i < word.size(); ++i)
        {
            if (p->sub[word[i]-'a'] == nullptr)
                p->sub[word[i]-'a'] = new Tree();
            p = p->sub[word[i]-'a'];
        }
        p->word = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        auto p = root;
        for (int i = 0; i < word.size(); ++i)
        {
            if (p->sub[word[i]-'a'] == nullptr)
                return false;
            p = p->sub[word[i]-'a'];
        }
        return p->word;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        auto p = root;
        for (int i = 0; i < prefix.size(); ++i)
        {
            if (p->sub[prefix[i]-'a'] == nullptr)
                return false;
            p = p->sub[prefix[i]-'a'];
        }
        return true;
    }
};

int main()
{
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple");   // returns true
    cout << trie.search("app");     // returns false
    cout << trie.startsWith("app"); // returns true
    trie.insert("app");
    cout << trie.search("app"); // returns true
    return 0;
}