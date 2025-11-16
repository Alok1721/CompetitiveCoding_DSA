#include<bits/stdc++.h>
using namespace std;
void topSort(unordered_map<int,vector<int>>&graph,int n,vector<int>&result)
{
    vector<int>indegree(n+1,0);
    for(auto it:graph)
    {
        for(auto nei:it.second)
        {
            indegree[nei]++;
        }
    }
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        result.push_back(curr);
        for(auto nei:graph[curr])
        {
            indegree[nei]--;
            if(indegree[nei]==0)
            {
                q.push(nei);
            }
        }
    }
    return ;
}
int main()
{

    int n,m;
    cin>>n>>m;
    unordered_map<int,vector<int>> graph;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    vector<int>result;
    topSort(graph,n,result);
    if(result.size()!=n)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else
    {
        for(int node:result)
        {
            cout<<node<<" ";
        }
        cout<<endl;
    }
    return 0;
}