#include "header.h"

#define rep(i, f, t, s) for (int i = f; i <= t; i += s)
#define repd(i, f, t, s) for (int i = f; i >= t; i -= s)
#define mk(a,b) make_pair(a,b)
#define sqr(a) ((a) * (a))
template<class Ty1,class Ty2> 
inline const pair<Ty1,Ty2> operator+(const pair<Ty1, Ty2>&p1, const pair<Ty1, Ty2>&p2)
{
    return mk(p1.first + p2.first,p1.second + p2.second);
}
template<class Ty1, class Ty2> 
inline const pair<Ty1, Ty2> operator-(const pair<Ty1, Ty2>&p1, const pair<Ty1, Ty2>&p2)
{
    return mk(p1.first - p2.first,p1.second - p2.second);
}

// Solution Here
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mapper1;
        unordered_map<char,char> mapper2;
        for (int i=0;i<s.size();++i){
            if (mapper1.find(s[i])==mapper1.end()){
                mapper1[s[i]]=t[i];
            }else{
                if (mapper1[s[i]]!=t[i]) return false;
            }
            if (mapper2.find(s[i])==mapper2.end()){
                mapper2[s[i]]=t[i];
            }else{
                if (mapper2[s[i]]!=t[i]) return false;
            }
        }
        return true;
    }
};

int main()
{
    return 0;
}