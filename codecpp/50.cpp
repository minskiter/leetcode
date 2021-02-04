#include "header.h";

class Solution {
public:
    double myPow(double x, int n) {
        long long f=n;
        f=f>0?f:-f;
        double ans=1.0;
        while (f!=0){
            if ((f&1)!=0){
                ans*=x;
            }
            x*=x;
            f>>=1;
        }
        return n<0?1.0/ans:ans;
    }
};

int main(){
    Solution s;
    cout << fixed << setprecision(5) << s.myPow(2,-2);
    return 0;
}