#include<bits/stdc++.h>
using namespace std;
struct State{
    int x,y;
};
vector<pair<int,int>> directions={{-1,0},{1,0},{0,-1},{0,1}};
vector<char> dirChars={'U','D','L','R'};

bool canReachEnd(vector<string>&grid,vector<char>&path)
{
    int h=grid.size();
    int w=grid[0].size();
    vector<vector<bool>> visited(h,vector<bool>(w,false));
    vector<vector<int>>dist(h,vector<int>(w,INT_MAX));
    vector<vector<int>>playerDist(h,vector<int>(w,INT_MAX));
    //search for 'M'
    queue<State>q;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(grid[i][j]=='M')
            {
                State start={i,j};
                q.push(start);
                visited[i][j]=true;
                dist[i][j]=0;
            }
        }
    }
    //use multi-source bfs and find the dist of each cell from nearest 'M'
    while(!q.empty())
    {
        auto currStates=q.front();
        q.pop();
        int x=currStates.x;
        int y=currStates.y;
        int currDist=dist[x][y];
        for(auto dir:directions)
        {
            int nx=x+dir.first;
            int ny=y+dir.second;
            if(nx>=0 && nx<h && ny>=0 && ny<w && grid[nx][ny]!='#' && !visited[nx][ny])
            {
                visited[nx][ny]=true;
                dist[nx][ny]=currDist+1;
                State nextState={nx,ny};
                q.push(nextState);
            }
        }
    }
    //now do bfs from 'A' to find path to any boundary cell and ensure we reach before any 'M'
    visited.assign(h,vector<bool>(w,false));
    vector<vector<pair<int,int>>> parent(h, vector<pair<int,int>>(w, {-1,-1}));
    q=queue<State>();
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(grid[i][j]=='A')
            {
                State start={i,j};
                parent[i][j]={-1,-1};
                q.push(start);
                visited[i][j]=true;
                playerDist[i][j]=0;
            }
        }
    }
    while(!q.empty())
    {
        auto currStates=q.front();
        q.pop();
        int x=currStates.x;
        int y=currStates.y;
        //check if boundary cell
        if(x==0 || x==h-1 || y==0 || y==w-1)
        {
            //reconstruct path
            vector<char> currPath;
            int cx=x;
            int cy=y;
            while(parent[cx][cy].first!=-1 && parent[cx][cy].second!=-1)
            {
                int px=parent[cx][cy].first;
                int py=parent[cx][cy].second;
                if(px==cx-1 && py==cy) currPath.push_back('D');
                else if(px==cx+1 && py==cy) currPath.push_back('U');
                else if(px==cx && py==cy-1) currPath.push_back('R');
                else if(px==cx && py==cy+1) currPath.push_back('L');
                cx=px;
                cy=py;
            }
            reverse(currPath.begin(),currPath.end());
            path=currPath;
            return true;
        }
        for(auto dir:directions)
        {
            int nx=x+dir.first;
            int ny=y+dir.second;
            if(nx>=0 && nx<h && ny>=0 && ny<w && grid[nx][ny]!='#' && !visited[nx][ny])
            {
                //check if we can reach before monster
                if(playerDist[x][y]+1<dist[nx][ny])
                {
                    visited[nx][ny]=true;
                    parent[nx][ny]={x,y};
                    playerDist[nx][ny]=playerDist[x][y]+1;
                    State nextState={nx,ny};
                    q.push(nextState);
                }
            }
        }
    }
    return false;

}



int main()
{
    int h,w;
    cin>>h>>w;
    vector<string>grid(h);
    for(int i=0;i<h;i++)
    {
        cin>>grid[i];
    }
    vector<char>path;
    if(canReachEnd(grid,path))
    {
        cout<<"YES"<<endl;
        cout<<path.size()<<endl;
        for(char dir:path)
        {
            cout<<dir;
        }
        cout<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}