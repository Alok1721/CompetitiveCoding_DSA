#include <bits/stdc++.h>
using namespace std;
int ans;
void dfs(unordered_map<int,vector<int>>&graph,int src,int dest,int currXor,int parent,vector<int>&points)
{
    currXor^=points[src];
 if(src==dest)
 {
    ans+=currXor;
    return;
 }   
 for(auto child:graph[src])
 {
    if(child!=parent)
    {
        dfs(graph,child,dest,currXor,src,points);
    }
 }
}
int findXorPath(vector<int>&points,vector<vector<int>>&edges)
{
    unordered_map<int,vector<int>>graph;
    for(auto it:edges)
    {
        graph[it[0]].push_back(it[1]);
        graph[it[1]].push_back(it[0]);
    }
    ans=0;
    int n=points.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int currXor=0;
            dfs(graph,i,j,currXor,-1,points);
        }
    }
    return ans;

}

int main()
{
    int n;
    cin>>n;
    vector<int>points(n);
    for(int i=0;i<n;i++)
    {
        cin>>points[i];
    }
    vector<vector<int>>edges;
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        edges.push_back({u-1,v-1});
    }
    cout<<findXorPath(points,edges);//find the xor of all pair of path where x<=y
    return 0;
}