#include "header.h"

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans={0};
        if (n==0) return ans;
        ans.push_back(1);
        if (n==1) return ans;
        for (int i=1;i<n;++i){
            int len = ans.size();
            for (int j=0;j<len;++j){
                ans.push_back(ans[len-j-1]+(1<<i));
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    const int n=4;
    auto arr = s.grayCode(n);
    for (auto item:arr){
        fmt::printBin(item,n);
    }
    return 0;
}