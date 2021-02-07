#include "header.h"

class Solution
{
public:
    string simplifyPath(string path)
    {
        stack<string> curPath;
        int i=0;
        while (i < path.size())
        {
            if (path[i] == '/')
            {
                string temp = "";
                if (i+1>=path.size()) break;
                while (i+1<path.size() && path[++i] != '/')
                {
                    temp = temp + char(path[i]);
                }
                if (temp == "..")
                {
                    if (curPath.size() > 0)
                        curPath.pop();
                }
                else if (temp != "." && temp != "")
                {
                    curPath.push(temp);
                }
            }else{
                break;
            }
        }
        string ans;
        while (curPath.size() > 0)
        {
            ans = "/" + curPath.top() + ans;
            curPath.pop();
        }
        if (ans.size() == 0)
            ans = "/";
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.simplifyPath("/a//b////c/d//././/..");
    return 0;
}