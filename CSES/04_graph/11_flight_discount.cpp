#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void dijikstra(unordered_map<ll,vector<pair<ll,ll>>>&graph,ll start,vector<ll>&dist)
{
    dist[start]=0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    pq.push({0,start});
    while(!pq.empty())
    {
        auto curr=pq.top();
        pq.pop();
        ll currDist=curr.first;
        ll currNode=curr.second;
        if(currDist>dist[currNode])continue;
        for(auto nei:graph[currNode])
        {
            ll nextNode=nei.first;
            ll edgeWeight=nei.second;
            if(currDist+edgeWeight<dist[nextNode])
            {
                dist[nextNode]=currDist+edgeWeight;
                pq.push({dist[nextNode],nextNode});
            }
        }
    }
    return ;
}



ll minPath(unordered_map<ll,vector<pair<ll,ll>>>&graph,unordered_map<ll,vector<pair<ll,ll>>>&revGraph, ll start,ll city,vector<vector<ll>>&edges)
{

    vector<ll>dist1(city,LLONG_MAX),dist2(city,LLONG_MAX);
    dijikstra(graph,start,dist1);
    dijikstra(revGraph,city-1,dist2);
    ll ans=LLONG_MAX;
    // cout<<"Distance from start to each city: ";
    // for(int i=0;i<city;i++)
    // {
    //     cout<<dist1[i]<<" ";
    // }
    // cout<<endl;
    // cout<<"Distance from end to each city: ";
    // for(int i=0;i<city;i++)in
    // {
    //     cout<<dist2[i]<<" ";
    // }
    // cout<<endl;
    for(int i=0;i<edges.size();i++)
    {
        ll u=edges[i][0];
        ll v=edges[i][1];
        ll w=edges[i][2];
        if(dist1[u]!=LLONG_MAX && dist2[v]!=LLONG_MAX)
        {
            ans=min(ans,dist1[u]+dist2[v]+w/2);
        }
    }
    return ans;
}


int main()
{
    ll city,connections;
    cin>>city>>connections;
    unordered_map<ll,vector<pair<ll,ll>>> graph,revGraph;
    vector<vector<ll>>edges;
    for(int i=0;i<connections;i++)
    {
        ll  u,v;
        ll w;
        cin>>u>>v>>w;
        graph[u-1].push_back({v-1,w});
        revGraph[v-1].push_back({u-1,w});
        edges.push_back({u-1,v-1,w});
    }
    cout<<minPath(graph,revGraph,0,city,edges)<<endl;
    return 0;

}