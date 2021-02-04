#include "header.h"

#define ll long long 
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        map<int, int> values;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (values.find(nums[i]) == values.end())
            {
                values[nums[i]] = 1;
            }
            else
            {
                values[nums[i]]++;
            }
        }
        vector<vector<int>> ans;
        set<long long> sets;
        for (int i=0;i<nums.size();++i){
            for (int j=i+1;j<nums.size();++j){
                int a=nums[i],b=nums[j],left=-a-b,cnt=0;
                if (left==a) ++cnt;
                if (left==b) ++cnt;
                if (values.find(left)!=values.end() && values[left]>cnt){
                    ll temp = (ll)a*100000+(ll)b;
                    if (sets.find(temp)==sets.end()){
                        sets.insert(temp);
                        ans.push_back(vector<int>{
                            a,b,left
                        });
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> temp={
        -1,0,1,2,-1,-4
    };
    vector<vector<int>> temp2 = s.threeSum(temp);
    fmt::printArray2(temp2);
    return 0;
}