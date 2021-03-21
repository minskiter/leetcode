#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
#include <iomanip>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <numeric>
using namespace std;

#define nullint INT_MIN

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    void Parse(vector<int> &tree)
    {
        if (tree.size() == 0)
        {
            return;
        }
        val = tree[0];
        auto buildTree = [&tree](auto &&self, TreeNode *root, int pos) {
            if (pos > tree.size())
                return;
            root->val = tree[pos - 1];
            if ((pos << 1) <= tree.size() && tree[(pos << 1) - 1] != nullint)
            {
                root->left = new TreeNode();
                self(self, root->left, pos << 1);
            }
            if ((pos << 1) < tree.size() && tree[pos << 1] != nullint)
            {
                root->right = new TreeNode();
                self(self, root->right, (pos << 1) + 1);
            }
        };
        buildTree(buildTree, this, 1);
    }
    void PrintInorder()
    {
        auto printTree = [](auto &&self, TreeNode *root) {
            if (root == nullptr)
                return; // Important 否则编译识别不出lambda的类型
            if (root->left)
            {
                self(self, root->left);
            }
            cout << root->val << ",";
            if (root->right)
            {
                self(self, root->right);
            }
        };
        cout << "[";
        printTree(printTree, this);
        cout << '\b' << "]" << endl;
    }
    int GetMax()
    {
        auto getMax = [](auto &&self, TreeNode *root) {
            if (root == nullptr)
            {
                return 0;
            }
            int ans = root->val;
            if (root->left)
                ans = max(ans, self(self, root->left));
            if (root->right)
                ans = max(ans, self(self, root->right));
            return ans;
        };
        return getMax(getMax, this);
    }
    int GetDeepth()
    {
        auto getMax = [](auto &&self, TreeNode *root) {
            if (root == nullptr)
            {
                return 0;
            }
            return max(self(self, root->left), self(self, root->right)) + 1;
        };
        return getMax(getMax, this);
    }
    void PrintTree()
    {
        auto echo = [](auto &&self, TreeNode *root, int pos = 0) {
            if (root == nullptr)
            {
                for (int i = 0; i < pos; ++i)
                {
                    cout << '\t';
                }
                cout << '*' << endl;
                return;
            }
            self(self, root->right, pos + 1);
            for (int i = 0; i < pos; ++i)
            {
                cout << '\t';
            }
            cout << root->val << endl;
            self(self, root->left, pos + 1);
        };
        echo(echo, this);
    }
    vector<int> ToVector()
    {
        int deepth = GetDeepth();
        vector<int> tree((1 << deepth) - 1, nullint);
        auto toVector = [&tree](auto &&self, TreeNode *root, int index) {
            if (root == nullptr)
            {
                return;
            }
            tree[index - 1] = root->val;
            self(self, root->left, index * 2);
            self(self, root->right, index * 2 + 1);
        };
        toVector(toVector, this, 1);
        return tree;
    }
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    ListNode *Print()
    {
        ListNode *head = this;
        while (head != nullptr)
        {
            cout << head->val;
            head = head->next;
            if (head != nullptr)
            {
                cout << "->";
            }
            else
            {
                cout << endl;
            }
        }
        return this;
    }
    ListNode *Parse(vector<int> &a)
    {
        if (a.size() == 0)
            return nullptr;
        ListNode *head = nullptr;
        ListNode *p = nullptr;
        for (int i = 0; i < a.size(); ++i)
        {
            if (head == nullptr)
            {
                head = new ListNode(a[i], nullptr);
                p = head;
            }
            else
            {
                p->next = new ListNode(a[i], nullptr);
                p = p->next;
            }
        }
        val = head->val;
        next = head->next;
        delete head;
        return this;
    }
};

#ifndef NeighborNode
#ifndef RandomNode
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
#else
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
#endif
#else
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
    void Parse(vector<vector<int>> map)
    {
        Node *nodes[101] = {nullptr};
        for (int i = 0; i < map.size(); ++i)
        {
            if (i == 0)
            {
                val = 1;
                nodes[i] = this;
            }
            else
                nodes[i] = new Node(i + 1);
        }
        for (int i = 0; i < map.size(); ++i)
        {
            for (int j = 0; j < map[i].size(); ++j)
            {
                nodes[i]->neighbors.push_back(nodes[map[i][j] - 1]);
            }
        }
    }
    void Print()
    {
        vector<bool> vis(101, false);
        auto dfs = [&vis](auto &&self, Node *p) {
            if (p == nullptr || vis[p->val])
                return;
            vis[p->val] = true;
            cout << "[" << p << ":" << p->val << "]:";
            for (int i = 0; i < p->neighbors.size(); ++i)
            {
                if (i != 0)
                    cout << ',';

                cout << p->neighbors[i] << "-";
                cout << p->neighbors[i]->val;
            }
            cout << endl;
            for (int i = 0; i < p->neighbors.size(); ++i)
            {
                self(self, p->neighbors[i]);
            }
        };
        dfs(dfs, this);
    }
};
#endif

class fmt
{
public:
    template <typename T>
    static void printArray(vector<T> temp)
    {
        cout << '[';
        for (int i = 0; i < temp.size(); ++i)
        {
            if (typeid(temp[i]) == typeid(string))
            {
                cout << "\"";
            }
            cout << temp[i];
            if (typeid(temp[i]) == typeid(string))
            {
                cout << "\"";
            }
            if (i == temp.size() - 1)
            {
            }
            else
            {
                cout << ',';
            }
        }
        cout << ']';
    }

    template <typename T>
    static void printArray2(vector<T> temp)
    {
        cout << '[';
        for (int i = 0; i < temp.size(); ++i)
        {
            if (i == 0)
            {
                cout << endl;
            }
            cout << "  ";
            fmt::printArray(temp[i]);
            if (i == temp.size() - 1)
            {
                cout << endl;
            }
            else
            {
                cout << ',' << endl;
            }
        }
        cout << ']' << endl;
    }

    template <typename T>
    static void printBin(T num, int length = -1)
    {
        string s = "";
        int len = 0;
        while (num)
        {
            s = char((num & 1) + '0') + s;
            num >>= 1;
            ++len;
        }
        while (len++ < length)
        {
            s = "0" + s;
        }
        cout << s << endl;
    }
};

template <typename T, typename V>
ostream &operator<<(ostream &output, const pair<T, V> &p)
{
    output << '(' << p.first << ',' << p.second << ')';
    return output;
}

template <typename T>
ostream &operator<<(ostream &output, const vector<T> &p)
{
    fmt::printArray(p);
    return output;
}
