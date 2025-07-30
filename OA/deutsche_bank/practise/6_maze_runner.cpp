#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>>dirs={{1,0},{-1,0},{0,1},{0,-1}};
int passThroughDoor(vector<vector<char>>& maze,pair<int,int>start,pair<int,int>end)
{
    int m=maze.size();
    int n=maze[0].size();
    queue<pair<int,int>>q;
    q.push(start);
    int steps=0;
    vector<vector<bool>>visited(m,vector<bool>(n,false));
    visited[start.first][start.second]=true;
    while(!q.empty())
    {
        
        int size=q.size();
        while(size--)
        {
            auto curr=q.front();
            q.pop();
            int x=curr.first;
            int y=curr.second;
            if(x==end.first && y==end.second)
            {
            return steps;
            }
        
            for(auto dir:dirs)
            {
                int newx=x+dir.first;
                int newy=y+dir.second;
                if(newx<0 || newx>=m || newy<0 || newy>=n || maze[newx][newy]=='*' || visited[newx][newy])
                {
                    continue;
                }
                q.push({newx,newy});
                visited[newx][newy]=true;
            }
        }
        steps++;
    }
    return -1; 
}

int passThroughWall(vector<vector<char>>& maze,pair<int,int>start,pair<int,int>end)
{
    int m=maze.size();
    int n=maze[0].size();
    queue<pair<int,int>>q;
    q.push(start);
    int steps=0;
    vector<vector<bool>>visited(m,vector<bool>(n,false));
    visited[start.first][start.second]=true;
    while(!q.empty())
    {
        
        int size=q.size();
        while(size--)
        {
            auto curr=q.front();
            q.pop();
            int x=curr.first;
            int y=curr.second;
            if(x==end.first && y==end.second)
            {
            return steps;
            }
        
            for(auto dir:dirs)
            {
                int newx=x+dir.first;
                int newy=y+dir.second;
                if(newx<0 || newx>=m || newy<0 || newy>=n || maze[newx][newy]=='#' || visited[newx][newy])
                {
                    continue;
                }
                q.push({newx,newy});
                visited[newx][newy]=true;
            }
        }
        steps++;
    }
    return -1; 
}




int main()
{
    int m,n;
    cin>>m>>n;
    vector<vector<char>> maze(m,vector<char>(n));//*->wall #->door .->path
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>maze[i][j];
        }
    }

    pair<int,int>start={0,0};
    pair<int,int>end={m-1,n-1};
    // max(passThroughDoor(maze,start,end),passThroughWall(maze,start,end));
    // cout<<max(passThroughDoor(maze,start,end),passThroughWall(maze,start,end));
    cout<<passThroughDoor(maze,start,end)<<endl;
    cout<<passThroughWall(maze,start,end)<<endl;
    return 0;
}