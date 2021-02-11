#include "header.h"

class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> ans;
        if (s.size() < 4 || s.size() > 12)
        {
            return ans;
        }
        // 预处理
        vector<vector<int>> poses(s.size()+1);
        poses[0].push_back(0);
        for (int i=0;i<s.size();++i){
            if (isIpAddr(s.substr(i,1))){
                poses[i+1].push_back(1);
            }
            if (i>0 && isIpAddr(s.substr(i-1,2))){
                poses[i+1].push_back(2);
            }
            if (i>1 && isIpAddr(s.substr(i-2,3))){
                poses[i+1].push_back(3);
            }
        }
        search(ans,"",s,poses,s.size(),0);
        return ans;
    }

private:
    void search(vector<string> & ans,string ip,string & s,vector<vector<int>> & poses,int deepth,int count){
        if (deepth<=0){
            if (count==4){
                ans.push_back(ip);
            }
            return;
        }
        for (int i=0;i<poses[deepth].size();++i){
            if (deepth-poses[deepth][i]<=0){
                search(ans,s.substr(deepth-poses[deepth][i],poses[deepth][i])+ip,s,poses,deepth-poses[deepth][i],count+1);
            }else{
                search(ans,"."+s.substr(deepth-poses[deepth][i],poses[deepth][i])+ip,s,poses,deepth-poses[deepth][i],count+1);
            }
        }
    }
    bool isIpAddr(string ipnode)
    {
        if (ipnode.size() > 1)
        {
            if (ipnode[0] == '0')
                return false;
        }
        if (ipnode.size() < 0 && ipnode.size() > 3)
            return false;
        int ans = ipnode[0] - '0';
        if (ipnode.size() > 1)
        {
            ans = ans * 10 + ipnode[1] - '0';
        }
        if (ipnode.size() > 2)
        {
            ans = ans * 10 + ipnode[2] - '0';
        }
        if (ans >= 0 && ans <= 255)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    fmt::printArray(s.restoreIpAddresses("101023"));
    return 0;
}