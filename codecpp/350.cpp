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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> intersec(nums1.size()+nums2.size());
        auto itor = set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), intersec.begin());
        intersec.resize(itor-intersec.begin());
        return intersec;
    }
};

int main()
{
    return 0;
}