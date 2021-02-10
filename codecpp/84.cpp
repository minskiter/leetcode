#include "header.h"

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> height;
        int ans=0;
        for (int i=0;i<heights.size();++i){
            while (!height.empty() && heights[i]<heights[height.top()]){
                int index = height.top();
                height.pop();
                int l = height.empty()?0:height.top()+1;
                ans=max(ans,(i-l)*heights[index]);
            }
            height.push(i);
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> temp = {2,1,2};
    cout << s.largestRectangleArea(temp);
    return 0;
}