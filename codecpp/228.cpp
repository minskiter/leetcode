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
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size()==0) return vector<string>();
        vector<string> ans;      
        int left = nums[0],right = left;
        for (int i=1;i<=nums.size();++i){
            if (i==nums.size() || right+1!=nums[i]){
                ostringstream os;
                os << left;
                if (left!=right){
                    os << "->" << right;
                }
                ans.emplace_back(os.str());
                if (i!=nums.size())
                    left = nums[i];
            }
            if (i!=nums.size())
                right = nums[i];
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {-1};
    cout << Solution().summaryRanges(nums);
    return 0;
}