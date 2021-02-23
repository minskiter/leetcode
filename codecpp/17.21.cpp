#include "header.h"

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int sum = 0, maxH = 0;
        for (int i = 0; i < height.size(); ++i)
        {
            sum += height[i];
            if (maxH<height[i]){
                sum+=i*(height[i]-maxH);
                maxH=height[i];
            }
        }
        maxH =0;
        for (int i=height.size()-1;i>=0;--i){
            if (height[i]>maxH){
                sum+=(height.size()-i-1)*(height[i]-maxH);
                maxH=height[i];
            }
        }
        return maxH*height.size()-sum;
    }
};

int main()
{
    vector<int> input = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << Solution().trap(input);
    return 0;
}