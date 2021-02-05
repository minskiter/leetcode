#include "header.h"

class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        search(ans,n,k,0,(1<<n)-1);
        return ans;
    }
private:
    bool search(string & ans,int n,int &k,int deepth,int visited){
        if (deepth==n){
            --k;
            return k==0;
        }
        for (int i=0;i<n;++i){
            if ((1<<i)&visited){
                ans=ans+char(i+'1');
                if (search(ans,n,k,deepth+1,visited-(1<<i))){
                    return true;
                }
                ans.pop_back();
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    cout << s.getPermutation(4,9);
    return 0;
}