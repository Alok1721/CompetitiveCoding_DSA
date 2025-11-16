#include<bits/stdc++.h>
using namespace std;
const int log=20;
void buildBinaryLiftingTable(unordered_map<int,vector<int>>&graph,vector<vector<int>>&up,int n)
{
    for(int i=0;i<n;i++)
    {
        up[i][0]=graph[i][0];
    }
    for(int jump=1;jump<log;jump++)
    {
        for(int node=0;node<n;node++)
        {
            up[node][jump]=up[up[node][jump-1]][jump-1];
        }
    }
}
int main()
{
    int planet,query;
    cin>>planet>>query;
    unordered_map<int,vector<int>> graph;
    for(int i=0;i<planet;i++)
    {
        int v;
        cin>>v;
        graph[i].push_back(v-1);
    }
    vector<vector<int>>up(planet,vector<int>(log));
    buildBinaryLiftingTable(graph,up,planet);
    
    for(int i=0;i<query;i++)
    {
        int node,k;
        cin>>node>>k;
        node--;
        for(int bit=0;bit<log;bit++)
        {
            if(k&(1<<bit))
            {
                node=up[node][bit];
            }
        }
        cout<<node+1<<endl;

    }
    return 0;

}