#include "header.h"

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<int> buffer(1e4*2+2,0);
        vector<vector<int>> ans;
        for (int i=0;i<intervals.size();++i){
            buffer[intervals[i][0]*2]++;
            buffer[intervals[i][1]*2+1]--;
        }
        buffer[newInterval[0]*2]++;
        buffer[newInterval[1]*2+1]--;
        int cur=0;
        int left=0;
        for (int i=0;i<1e4*2+2;++i){
            if (cur<=0 && cur+buffer[i]>0){
                left=i;
            }else if (cur>0 && cur+buffer[i]<=0){
                vector<int> temp = {left/2,(i-1)/2};
                ans.push_back(temp);
            }
            cur+=buffer[i];
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>> intervals={{1,3},{6,9}};
    vector<int> newIntervals = {2,5};
    fmt::printArray2(s.insert(intervals,newIntervals));
    return 0;
}