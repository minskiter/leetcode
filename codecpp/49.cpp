#include "header.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> ans;
        for (int i=0;i<strs.size();++i){
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            if (ans.find(temp)!=ans.end()){
                ans[temp].push_back(strs[i]);
            }else{
                vector<string> tempSet;
                tempSet.push_back(strs[i]);
                ans[temp]=tempSet;
            }
        }
        vector<vector<string>> ansV;
        for (auto ptrM=ans.begin();ptrM!=ans.end();ptrM++){
            // vector<string> temp;
            // for (auto ptrS=ptrM->second.begin();ptrS!=ptrM->second.end();++ptrS){
            //     temp.push_back(ptrS->data());
            // }
            ansV.push_back(ptrM->second);
        }
        return ansV;
    }   
};

int main(){
    Solution s;
    vector<string> strs = {"",""};
    fmt::printArray2(s.groupAnagrams(strs));
    return 0;
}