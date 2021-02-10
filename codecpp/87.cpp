#include "header.h"

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1==s2){
            return true;
        }
        vector<int> charCount(26,0);
        for (int i=0;i<s1.size();++i){
            charCount[s1[i]-'a']++;
            charCount[s2[i]-'a']--;
        }
        for (int i=0;i<26;++i){
            if (charCount[i]!=0)
                return false;
        }
        for (int i=1;i<s1.size();++i){
            if ((isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i),s2.substr(i))) || (isScramble(s1.substr(0,i),s2.substr(s2.size()-i)) && isScramble(s1.substr(i),s2.substr(0,s2.size()-i)))){
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    cout << s.isScramble("abc","bca");
    return 0;
}