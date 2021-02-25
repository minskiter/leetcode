#include "header.h"

#define rep(i, f, t, s) for (int i = f; i <= (int)t; i += s)
#define repd(i, f, t, s) for (int i = f; i >= (int)t; i -= s)
#define mk(a,b) make_pair(a,b)
#define sqr(a) ((a) * (a))
template<class Ty1,class Ty2> 
inline const pair<Ty1,Ty2> operator+(const pair<Ty1, Ty2>&p1, const pair<Ty1, Ty2>&p2)
{
    return mk(p1.first + p2.first,p1.second + p2.second);
}
template<class Ty1, class Ty2> 
inline const pair<Ty1, Ty2> operator-(const pair<Ty1, Ty2>&p1, const pair<Ty1, Ty2>&p2)
{
    return mk(p1.first - p2.first,p1.second - p2.second);
}

// Solution Here
class Solution {
private:
    void addEdge(int f,int t,vector<int> & head,vector<int> &nxt,vector<int> &edges){
        edges.push_back(t);
        nxt.push_back(head[f]);
        head[f]=nxt.size()-1;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> head(numCourses,-1),edges,nxt,in(numCourses),ans;
        rep(i,0,prerequisites.size()-1,1){
            addEdge(prerequisites[i][1],prerequisites[i][0],head,nxt,edges);
            ++in[prerequisites[i][0]];
        }
        int cnt=0,front,p;
        queue<int> q;
        rep(i,0,numCourses-1,1){
            if (in[i]==0){
                q.emplace(i);
                ans.emplace_back(i);
            }
        }
        while (!q.empty()){
            front = q.front();
            q.pop();
            p = head[front];
            while (p!=-1){
                --in[edges[p]];
                if (in[edges[p]]==0){
                    ans.emplace_back(edges[p]);
                    q.emplace(edges[p]);
                }
                p=nxt[p];

            }
        }
        if (ans.size()!=numCourses){
            return vector<int>();
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
    fmt::printArray(Solution().findOrder(4,prerequisites));
    return 0;
}