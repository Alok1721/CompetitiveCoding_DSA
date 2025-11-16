#include<bits/stdc++.h>
using namespace std;

bool checkBipartite(int node,unordered_map<int,vector<int>>&graph,vector<int>&team,int color)
{
    team[node]=color;
    for(auto nei:graph[node])
    {
        if(team[nei]==-1)
        {
            if(!checkBipartite(nei,graph,team,1-color))
            {
                return false;
            }
        }
        else if(team[nei]==color)
        {
            return false;
        }
    }
    return true;

}


int main()
{
    int n,m;
    cin>>n>>m;
    unordered_map<int,vector<int>> graph;
    vector<pair<int,int>>friends;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        friends.push_back({a,b});
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }
    vector<int>team(n,-1);
    
    for(int i=0;i<n;i++)
    {
        if(team[i]==-1)
        {
            if(!checkBipartite(i,graph,team,0))
            {
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<team[i]+1<<" ";
    }
    cout<<endl;
    
    return 0;
}