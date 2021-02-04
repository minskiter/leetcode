#include "header.h"

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int newIndex=0;
        for (int i=0;i<nums.size();++i){
            if (nums[i]!=val){
                nums[newIndex++]=nums[i];
            }
        }
        return newIndex;
    }
};

int main(){
    vector<int> test = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    Solution s;
    int len = s.removeElement(test,1);
    cout << '[';
    for (int i = 0; i < len; ++i)
    {
        cout << test[i];
        if (i != len - 1)
            cout << ',';
    }
    cout << ']' << endl;
    return 0;
}