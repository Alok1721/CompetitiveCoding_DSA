#include<bits/stdc++.h>
using namespace std;

vector<int>bestPath;
void dfs(vector<vector<pair<int,int>>>&adj,int p,int v,int node,int cost,vector<int>&path,vector<bool>&visited)
{
    visited[node]=true;

    path.push_back(node);
    if(2*cost<=p && path.size()>=bestPath.size())
    {
        bestPath=path;
    }

    for(auto nei:adj[node])
    {
        if(!visited[nei.first])
        {
            dfs(adj,p,v,nei.first,cost+nei.second,path,visited);
        }
    }

    visited[node]=false;
    path.pop_back();
}

int main()
{

    int v,e;
    cin>>v>>e;
    int p;
    cin>>p;
    vector<vector<pair<int,int>>> adj(v+1);
    for(int i=0;i<e;i++)
    {
        int u,vv,w;
        cin>>u>>vv>>w;
        adj[u].push_back({vv,w});
        adj[vv].push_back({u,w});
    }
    int src=1;
    vector<int>path;
    vector<bool>visited(v+1,false);
    dfs(adj,p,v,1,0,path,visited);

    for(int vv:bestPath)
    {
        cout<<vv<<" ";
    }
    for(int i=bestPath.size()-2;i>=0;i--)
    {
        cout<<bestPath[i]<<" ";
    }
    cout<<endl;

    return 0;
}