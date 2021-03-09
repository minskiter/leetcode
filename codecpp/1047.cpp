#include "header.h"

#define rep(i, f, t, s) for (int i = f; i <= (int)t; i += s)
#define repd(i, f, t, s) for (int i = f; i >= (int)t; i -= s)
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
template <class Ty1, class Ty2>
bool inner(pair<Ty1,Ty2> pos,pair<Ty1,Ty2> leftTop,pair<Ty1,Ty2> rightBottom){
    if (pos.first>=leftTop.first && pos.second>=leftTop.second){
        if (pos.first<rightBottom.first && pos.second<rightBottom.second){
            return true;
        }
    }
    return false;
}

// Solution Here
class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> matches;
        for (int i=0;i<S.size();++i){
            if (!matches.empty() && matches.top()==S[i]){
                    matches.pop();
            }else{
                matches.emplace(S[i]);
            }
        }
        S.resize(matches.size());
        for (int i=(int)matches.size()-1;i>=0;--i){
            S[i]=matches.top();
            matches.pop();
        }
        return S;
    }
};

int main()
{
    return 0;
}