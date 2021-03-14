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

class BinaryIndexTree{
        vector<int> tree;
    public:
        BinaryIndexTree(int size):tree(vector<int>(size)){
        }
        void Add(int index,int val){
            for (;index<tree.size();index+=index&-index){
                tree[index]+=val;
            }
        }
        int PrefixSum(int index){
            int sum = 0;
            for (;index>0;index-=index&-index){
                sum+=tree[index];
            }
            return sum;
        }
};

// Solution Here
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        BinaryIndexTree tree(20002);
        vector<int> cnt{0};
        tree.Add(nums[nums.size()-1]+10001,1);
        for (int i=(int)nums.size()-2;i>=0;--i){
            cnt.emplace_back(tree.PrefixSum(nums[i]+10000));
            tree.Add(nums[i]+10001,1);
        }
        reverse(cnt.begin(),cnt.end());
        return cnt;
    }
};

int main()
{
    return 0;
}