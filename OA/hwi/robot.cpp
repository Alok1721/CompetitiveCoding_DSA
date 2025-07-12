#include<bits/stdc++.h>
using namespace std;
int maxMove=0;
vector<pair<int,int>> dirs={{1,0},{0,1},{-1,0},{0,-1}};
void dfs(vector<vector<char>>&grid,int m,int n,int i,int j,vector<vector<bool>>&visited,int count)
{
    if(i>=m || j>=n || i<0 || j<0 ||grid[i][j]=='X')return;

    visited[i][j]=true;
    count+=1;
    maxMove=max(maxMove,count);
    for(auto dir:dirs)
    {
        int nx=i+dir.first;
        int ny=j+dir.second;
        dfs(grid,m,n,nx,ny,visited,count);

    }

}

int findMaxEmptyCell(vector<vector<char>>&grid,int m,int n)
{
    vector<vector<bool>> visited(m,vector<bool>(n,false));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!visited[i][j])
            {
                dfs(grid,m,n,i,j,visited,0);
            }
        }
    }
    return maxMove;
}

int main ()
{
    int m,n;
    cin>>m>>n;
    vector<vector<char>> grid(m,vector<char>(n));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>grid[i][j];
        }
    }

    cout<<findMaxEmptyCell(grid,m,n);

    return 0;
}