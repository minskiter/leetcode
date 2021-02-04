#include "header.h"

class Solution {
public:
    int divide(int dividend, int divisor) {
        int f = 1;
        if (dividend<0){
            f=-f;
        }else{
            dividend=-dividend;
        }
        if (divisor<0){
            f=-f;
        }else{
            divisor=-divisor;
        }
        long long p = divisor;
        long long l = -1;
        long long ans=0;
        long long sum=0;
        while (true){
            if (p+sum>=0 || p+sum<dividend){
                if (l==-1){
                    if (f==1 && ans==INT_MIN){
                        return INT_MAX;
                    }
                    return -ans*f;
                }else{
                    p=divisor;
                    l=-1;
                }
            }else{
                ans+=l;
                sum+=p;
                p+=p;
                l+=l;
            }
        }
    }
};

int main(){
    Solution s;
    cout << s.divide(INT_MIN,-1) << endl;
    return 0;
}