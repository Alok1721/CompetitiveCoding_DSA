#include <bits/stdc++.h>
using namespace std;
void dfs(unordered_map<int,vector<int>>&graph,int node,unordered_set<int>&visited)
{
    cout<<node<<endl;
    visited.insert(node);
    for(auto nei:graph[node])
    {
        if(!visited.count(nei))
        {
            dfs(graph,nei,visited);
        }
    }
}

bool isMotherVertex(int n,vector<vector<int>>&edges)
{
    unordered_map<int,vector<int>>graph;
    for(auto e:edges)
    {
        graph[e[0]].push_back(e[1]);
    }
    for(int i=0;i<n;i++)
    {
        unordered_set<int>visited;
        dfs(graph,i,visited);
        if(visited.size()==n)
        {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    int e;
    cin>>n>>e;
    vector<vector<int>>edges;
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        edges.push_back({a,b});
    }    

    cout<<isMotherVertex(n,edges);
    return 0;
}
