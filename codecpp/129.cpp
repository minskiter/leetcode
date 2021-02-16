#include "header.h"

class Solution
{
public:
    int sumNumbers(TreeNode *root)
    {
        int sum = 0;
        Travese(root, 0, sum);
        return sum;
    }

private:
    void Travese(TreeNode *root, int num, int &sum)
    {
        if (root == nullptr)
        {
            return;
        }
        num = num * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr)
        {
            sum += num;
            return;
        }
        Travese(root->left, num, sum);
        Travese(root->right, num, sum);
    }
};

int main()
{
    vector<int> tree = {4,9,0,5,1};
    TreeNode * root = new TreeNode();
    root->Parse(tree);
    Solution s;
    cout << s.sumNumbers(root);
    return 0;
}