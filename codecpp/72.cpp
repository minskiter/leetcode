#include "header.h"

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(2,vector<int>(word2.size()+1,INT_MAX/2));
        for (int i=0;i<=word2.size();++i){
            dp[0][i]=i;
        }
        for (int i=1;i<=word1.size();++i){
            dp[i&1][0]=i;
            for (int j=1;j<=word2.size();++j){
                if (word1[i-1]==word2[j-1]){
                    dp[i&1][j]=dp[(i-1)&1][j-1];
                }else{
                    dp[i&1][j]=min(min(dp[(i-1)&1][j-1],dp[(i-1)&1][j]),dp[i&1][j-1])+1;
                }
            }
        }
        return dp[word1.size()&1][word2.size()];
    }
};

int main(){
    Solution s;
    cout << s.minDistance("intention","execution");
    return 0;
}