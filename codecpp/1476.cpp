#include "header.h"

#define rep(i,f,t,s) for (int i=f;i<=t;i+=s)
#define repd(i,f,t,s) for (int i=f;i>=t;i-=s)
class SubrectangleQueries
{
private:
    vector<vector<int>> matrix;

public:
    SubrectangleQueries(vector<vector<int>> &rectangle)
    {
        matrix = rectangle;
    }

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue)
    {
        rep(i,row1,row2,1){
            rep(j,col1,col2,1){
                matrix[i][j]=newValue;
            }
        }
    }

    int getValue(int row, int col)
    {
        return matrix[row][col];
    }
};

int main()
{
    return 0;
}