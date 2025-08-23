#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int n,vector<pair<int,int>>redEdges,vector<pair<int,int>>blueEdges)
{
    unordered_map<int,vector<pair<int,int>>>adj;
    for(auto e:redEdges)
    {
        adj[e.first].push_back({e.second,0});//0->red,1->blue
    }
    for(auto e:blueEdges)
    {
        adj[e.first].push_back({e.second,1});//0->red,1->blue
    }
    vector<vector<int>>dist(n,vector<int>(2,1e7));//dis,color dist[1]->color, dist[0]->distance
    queue<vector<int>>q;//node,prev_color
    dist[0][0]=dist[0][1]=0;
    q.push({0,-1,0});//start node,no_color previously,dist
    vector<vector<bool>>visited(n,vector<bool>(2,false));//donot visited teh same node with same state 
    
    while(!q.empty())
    {
        auto curr=q.front();
        q.pop();
        int node=curr[0];
        int prev_color=curr[1];
        int d=curr[2];
        for(auto nei:adj[node])
        {
            int next_node=nei.first;
            int next_color=nei.second;
            if(  next_color!=prev_color && dist[next_node][next_color]>1+d)
            {
                visited[next_color][next_color]=true;
                q.push({next_node,next_color,d+1});
                dist[next_node][next_color]=1+d;
            }
            
        }
    }
    vector<int>result(n);
    for(int i=0;i<n;i++)
    {
        int distance=min(dist[i][0],dist[i][1]);
        result[i]=distance==1e7?-1:distance;
    }
    
    return result;

}


int main()
{
    int n,red,blue;
    cin>>n>>red>>blue;
    vector<pair<int,int>>redEdges;
    for(int i=0;i<red;i++)
    {
        int a,b;
        cin>>a>>b;
        redEdges.push_back({a,b});
    }
    vector<pair<int,int>>blueEdges;
    for(int i=0;i<blue;i++)
    {
        int a,b;
        cin>>a>>b;
        blueEdges.push_back({a,b});
    }
    vector<int>result=shortestPath(n,redEdges,blueEdges);
    for(int i=0;i<n;i++)
    {
        cout<<result[i]<<" ";
    }
    cout<<endl;

    return 0;
}