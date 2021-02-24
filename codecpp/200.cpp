#include "header.h"

#define rep(i, f, t, s) for (int i = f; i <= t; i += s)
#define repd(i, f, t, s) for (int i = f; i >= t; i -= s)
#define mk(a, b) make_pair(a, b)
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
class Solution
{
    vector<pair<int,int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int numIslands(vector<vector<char>> &grid)
    {
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size()));
        queue<pair<int, int>> q;
        pair<int,int> pos,top;
        int cnt = 0;
        rep(i,0,grid.size()-1,1){
            rep(j,0,grid[i].size()-1,1){
                if (grid[i][j]=='1' && !vis[i][j]){
                    ++cnt;
                    q.push(mk(i,j));
                    vis[i][j]=true;
                    while (!q.empty()){
                        top = q.front();
                        q.pop();
                        rep(k,0,3,1){
                            pos = top+direction[k];
                            if (pos.first>=0 && pos.second>=0 && pos.first<grid.size() && pos.second<grid[0].size())
                            if (grid[pos.first][pos.second]=='1' && !vis[pos.first][pos.second]){
                                vis[pos.first][pos.second]=true;
                                q.push(pos);
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
};

int main()
{
    return 0;
}