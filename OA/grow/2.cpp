#include<bits/stdc++.h>
using namespace std;
void dfs(unordered_map<int,list<int>>graph,int node,vector<bool>&visited)
{
    visited[node]=true;
    for(auto it:graph[node])
    {
        if(!visited[it])
        {
            dfs(graph,it,visited);
        }
    }
}

int minEdgeToRemove(vector<vector<int>>&edges,int a,int b,int n)
{
    //building the graph
    unordered_map<int,list<int>>graph;
    for(auto it:edges)
    {
        int u=it[0];
        int v=it[1];
        graph[u].push_back(v);
    }   
    //store the incoming edges to b (because max we can remove all incoming edge)
    vector<int>incoming;
    for(auto it:edges)
    {
        if(it[1]==b)
        {
            incoming.push_back(it[0]);
        }
    }

    //find the path from a to b, which node help me to reach to the 
    vector<bool>visited(n,false);
    dfs(graph,a,visited);

    int ans=0;
    for(auto node:incoming)
    {
        if(visited[node])
        {
            ans++;
        }
    }
    return ans;
}

int main()
{

    int n,e;
    cin>>n>>e;
    int a,b;
    cin>>a>>b;
    a-=1;
    b-=1;
    vector<vector<int>>edges(e);
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        edges[i]={u-1,v-1};
    }

    cout<<minEdgeToRemove(edges,a,b,n);//edges to remove so that, it will not reachable from a->b
    return 0;
}