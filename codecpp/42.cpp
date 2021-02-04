#include "header.h"

class Solution
{
public:
    int trap(vector<int> &height)
    {
        if (height.size()==0){
            return 0;
        }
        int leftIndex = 0;
        int ans=0;
        for (int i = 1; i < height.size(); ++i)
        {   
            if (height[i]<=height[leftIndex]){
                ans+=height[leftIndex]-height[i];
            }else{
                leftIndex=i;
            }
        }
        if (leftIndex!=height.size()-1){
            int rightIndex = height.size()-1;
            for (int i=height.size()-1;i>leftIndex;--i){
                ans-=height[leftIndex]-height[i];
                if (height[i]<=height[rightIndex]){
                    ans+=height[rightIndex]-height[i];
                }else{
                    rightIndex=i;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> height = {4,2,0,3,2,1};
    cout << s.trap(height);
    return 0;
}