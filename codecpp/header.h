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
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    void Print()
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
    }
    void Parse(vector<int> &a)
    {
        if (a.size() == 0)
        {
            return;
        }
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
    }
};

class fmt
{
public:
    template <typename T>
    static void printArray(vector<T> temp)
    {
        cout << '[';
        for (int i = 0; i < temp.size(); ++i)
        {
            if (i == 0)
            {
                if (typeid(temp[i])==typeid(string)){
                    cout << endl;
                }
            }
            if (typeid(temp[i])==typeid(string)){
                cout << "\"";
            }
            cout << temp[i];
            if (typeid(temp[i])==typeid(string)){
                cout << "\"";
            }
            if (i == temp.size() - 1)
            {
                if (typeid(temp[i])==typeid(string)){
                    cout << endl;
                }
            }
            else
            {      
                cout << ',';
                if (typeid(temp[i])==typeid(string)){
                    cout << endl;
                }
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
            if (i==0){
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
            s = s + char((num & 1) + '0');
            num >>= 1;
            ++len;
        }
        while (len++ < length)
        {
            s += "0";
        }
        cout << s << endl;
    }
};