#include "header.h"

class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ansV;
        vector<int> ans;
        vector<bool> visisted(candidates.size(), false);
        search(ansV, ans, candidates, 0, target, visisted);
        return ansV;
    }

private:
    void search(vector<vector<int>> &ansV, vector<int> &ans, vector<int> &candidates, int deepth, int target, vector<bool> &visited)
    {
        if (target <= 0 || deepth >= candidates.size())
        {
            if (target == 0)
            {
                ansV.push_back(ans);
            }
            return;
        }
        
        search(ansV, ans, candidates, deepth + 1, target, visited);
        if (deepth>0 && candidates[deepth]==candidates[deepth-1] && !visited[deepth-1]){
            return;
        }
        ans.push_back(candidates[deepth]);
        visited[deepth] = true;
        search(ansV, ans, candidates, deepth + 1, target - candidates[deepth], visited);
        visited[deepth] = false;
        ans.pop_back();
    }
};

int main()
{
    Solution s;
    vector<int> test = {10,1,2,7,6,1,5};
    fmt::printArray2(s.combinationSum2(test, 8));
    return 0;
}