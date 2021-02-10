#include "header.h"

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1=m-1,p2=n-1,i=n+m-1,temp;
        while (p2>=0){
            if (p1>=0 && p2>=0){
                if (nums1[p1]>nums2[p2]){
                    nums1[i--]=nums1[p1--];
                }else{
                    nums1[i--]=nums2[p2--];
                }
            }else{
                nums1[i--]=nums2[p2--];
            }
        }
    }
};

int main(){
    Solution s;
    vector<int> nums1={4,5,6,0,0,0};
    vector<int> nums2={1,2,3};
    s.merge(nums1,3,nums2,3);
    fmt::printArray(nums1);
    return 0;
}