#include "header.h"

class Solution
{
public:
    vector<TreeNode *> generateTrees(int n)
    {
        vector<TreeNode *> tree;
        for (int i = 1; i <= n; ++i)
        {
            auto temp = search(1, i, n);
            for (int j = 0; j < temp.size(); ++j)
            {
                tree.push_back(temp[j]);
            }
        }
        return tree;
    }

private:
    vector<TreeNode *> search(int l, int mid, int r)
    {
        vector<TreeNode *> ans;
        if (l == r)
        {
            ans.push_back(new TreeNode(mid));
            return ans;
        }
        vector<TreeNode *> left, right;
        for (int i = l; i < mid; ++i)
        {
            auto ans = search(l, i, mid - 1);
            for (int j = 0; j < ans.size(); ++j)
            {
                left.push_back(ans[j]);
            }
        }
        for (int i = mid + 1; i <= r; ++i)
        {
            auto ans = search(mid + 1, i, r);
            for (int j = 0; j < ans.size(); ++j)
            {
                right.push_back(ans[j]);
            }
        }
        if (l == mid)
        {
            for (int j = 0; j < right.size(); ++j)
            {
                ans.push_back(new TreeNode(mid, nullptr, right[j]));
            }
        }
        for (int i = 0; i < left.size(); ++i)
        {
            if (mid == r)
            {
                ans.push_back(new TreeNode(mid, left[i], nullptr));
            }
            for (int j = 0; j < right.size(); ++j)
            {
                ans.push_back(new TreeNode(mid, left[i], right[j]));
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    s.generateTrees(3);
    return 0;
}