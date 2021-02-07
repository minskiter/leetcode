#include "header.h"

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(3,0);
        dp[0]=1;
        dp[1]=2;
        for (int i=2;i<n;++i){
            dp[i%3]=dp[(i-1)%3]+dp[(i-2)%3];
        }
        return dp[(n-1)%3];
    }
};

int main(){
    Solution s;
    cout << s.climbStairs(4);
    return 0;
}