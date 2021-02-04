#include "header.h"

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size()==0) return 0;
        vector<int> nxt(needle.size(),-1);
        int j=-1;
        for (int i=1;i<needle.size();++i){
            while (j!=-1 && needle[i]!=needle[j+1]) j=nxt[j];
            if (needle[i]==needle[j+1])++j;
            nxt[i]=j;
        }
        j=-1;
        for (int i=0;i<haystack.size();++i){
            while (j!=-1 && haystack[i]!=needle[j+1]) j=nxt[j];
            if (haystack[i]==needle[j+1]) ++j;
            if (j==needle.size()-1){
                return i-j;
            }
        }
        return -1;
    }
};

int main(){
    string haystack = "hellohello";
    string needle = "ohe";
    Solution s;
    cout << s.strStr(haystack,needle) << endl;
    return 0;
}