#include "header.h"

class Solution {
public:
    string multiply(string num1, string num2) {
        int len1=num1.size(),len2=num2.size();
        vector<int> ans(num1.size()+num2.size(),0);
        for (int i=len1-1;i>=0;--i){
            for (int j=len2-1;j>=0;--j){
                ans[len1+len2-i-j-2]+=(num1[i]-'0')*(num2[j]-'0');
            }
        }
        string ansS="";
        for (int i=0;i<ans.size()-1;++i){
            ans[i+1]+=ans[i]/10;
            ans[i]%=10;
        }
        len1 = ans.size();
        while (len1>0 && ans[--len1]==0);
        for (int i=len1;i>=0;--i){
             ansS=ansS+(char)(ans[i]+'0');
        }
        return ansS;
    }
};

int main(){
    Solution s;
    cout << s.multiply("9999999999","999") << endl;
    return 0;
}