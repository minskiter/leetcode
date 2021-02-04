#include "header.h"

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> bracket;
        bracket.push(0);
        int ans=0;
        for (int i=0;i<s.size();++i){
            if (s[i]=='('){
                bracket.push(0);
            }else{
                if (s[i]==')' && bracket.size()>1){
                    int top = bracket.top();
                    bracket.pop();
                    top+=2;
                    top+=bracket.top();
                    bracket.pop();
                    bracket.push(top);
                }else{
                    bracket.pop();
                    bracket.push(0);
                }
            }
            ans=max(ans,bracket.top());
        }
        return ans;
    }
};

int main(){
    Solution s;
    cout << s.longestValidParentheses(")()())()()(") << endl;
    return 0;
}