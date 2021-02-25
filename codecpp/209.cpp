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
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,r=-1,sum=0,len=INT_MAX;
        while (r+1<nums.size()){
            while (r+1<nums.size() && sum<target){
                sum+=nums[++r];
            }
            while (l<=r && sum>=target){
                len = min(r-l+1,len);
                sum-=nums[l++];
            }
        }
        if (len==INT_MAX) return 0;
        return len;
    }
};

int main()
{
    return 0;
}