#include<bits/stdc++.h>
using namespace std;
vector<int> dijsktra(vector<vector<pair<int,int>>>&adj,int src,int v,int dst)
{
    vector<int>dist(v+1,1e7);

    vector<int>parent(v+1,-1);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    dist[src]=0;
    pq.push({0,src});
    while(!pq.empty())
    {
        auto curr=pq.top();
        pq.pop();
        
        int node=curr.second;

        for(auto nei:adj[node])
        {
            int w=nei.second;
            if(dist[node]+w<dist[nei.first])
            {
                dist[nei.first]=dist[node]+w;
                parent[nei.first]=node;
                pq.push({dist[nei.first],nei.first});
            }
        }
    }

    vector<int> path;
    for(int p=dst;p!=-1;p=parent[p])
    {
        path.push_back(p);
    }
    reverse(path.begin(),path.end());
    return path;
}


int main()
{

    int v,e;
    cin>>v>>e;

    bool isOdd=v%2!=0;
    int pairs=v/2;
    
    vector<vector<pair<int,int>>> adj(v+1);
    vector<pair<int,int>> color_map;
    for(int i=0;i<e;i++)
    {
        int u,vv,w;
        cin>>u>>vv>>w;
        adj[u].push_back({vv,w});
        adj[vv].push_back({u,w});
    }

    for(int i=0;i<pairs;i++)
    {
        int a,b;
        cin>>a>>b;
        color_map.push_back({a,b});
    }
    if(isOdd)
    {
        int solo;
        cin>>solo;
        color_map.push_back({solo,solo});
    }

    int q;
    cin>>q;
    auto curr=color_map[q-1];
    int src=curr.first;
    int dst=curr.second;

    if(src==dst)
    {
        cout<<src<<endl;
        return 0;
    }
    vector<int>path=dijsktra(adj,src,v,dst);

    for(int vv:path)
    {
        cout<<vv<<" ";
    }
    cout<<endl;

    return 0;
}