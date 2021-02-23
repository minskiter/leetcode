#include "header.h"

#define rep(i, f, t, s) for (int i = f; i <= t; i += s)
#define repd(i, f, t, s) for (int i = f; i >= t; i -= s)
#define mk(a, b) make_pair(a, b)

// Solution Here
class Solution
{
public:
    int minOperations(vector<string> &logs)
    {
        int cnt = 0;
        rep(i, 0, logs.size() - 1, 1)
        {
            if (logs[i]=="../"){
                cnt = max(0,cnt-1);
            }else if (logs[i]=="./"){
            }else{
                cnt++;
            }
        }
        return cnt;
    }
};

int main()
{
    return 0;
}