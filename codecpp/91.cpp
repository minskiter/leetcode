#include "header.h"

class Solution {
public:
    int numDecodings(string s) {
        vector<int> ans(3,0);
        ans[0]=1;
        for (int i=1;i<=s.size();++i){
            ans[i%3]=0;
            if (s[i-1]>'0' && s[i-1]<='9')
                ans[i%3]=ans[(i-1)%3];
            if (i>1){
                int temp = s[i-1]-'0'+(s[i-2]-'0')*10;
                if (temp>=10 && temp<=26){
                    ans[i%3]+=ans[(i-2)%3];
                }
            }
        }
        return ans[s.size()%3];
    }
};

int main(){
    Solution s;
    cout << s.numDecodings("06");
    return 0;
}