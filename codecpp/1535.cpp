#include "header.h"

#define rep(i, f, t, s) for (int i = f; i <= t; i += s)
#define repd(i, f, t, s) for (int i = f; i >= t; i -= s)

class Solution
{
private:
public:
    int getWinner(vector<int> &arr, int k)
    {
        int maxi = 0;
        rep(i, 1, arr.size() - 1, 1)
        {
            if (arr[i] > arr[maxi])
            {
                if ((maxi == 0 && i - maxi > k) || (maxi != 0 && i - maxi >= k))
                    return arr[maxi];
                maxi = i;
            }
        }
        return arr[maxi];
    }
};

int main()
{
    Solution s;
    return 0;
}