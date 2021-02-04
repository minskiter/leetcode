#include "header.h"

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i;
        for (i=s.size()-1;i>=0;--i){
            if (s[i]!=' '){
                break;
            }
        }
        if (i<0) return 0;
        for (int j=i;j>=0;--j){
            if (s[j]==' '){
                return i-j;
            }
        }
        return i+1;
    }
};

int main(){
    Solution s;
    cout << s.lengthOfLastWord("abc");
    return 0;
}