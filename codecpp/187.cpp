#include "header.h"

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> dnas;
        if (s.size()<=10) return dnas;
        unordered_map<string,bool> sets;
        string tmp;
        for (int i=0;i<s.size()-9;++i){
            tmp = s.substr(i,10);
            if (sets.find(tmp)!=sets.end()){
                if (sets[tmp]){
                    sets[tmp]=false;
                    dnas.emplace_back(tmp);
                }
            }else{
                sets.emplace(tmp,true);
            }
        }
        return dnas;
    }
};

int main(){
    fmt::printArray(Solution().findRepeatedDnaSequences(""));
    return 0;
}