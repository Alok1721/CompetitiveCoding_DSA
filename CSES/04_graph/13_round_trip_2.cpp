#include<bits/stdc++.h>
using namespace std;
bool isValid(unordered_map<int,vector<int>>&graph,int node,vector<int>&path,vector<bool> &recStack,vector<bool>& visited)
{

    visited[node]=true;
    recStack[node]=true;
    path.push_back(node);
    for(auto nei:graph[node])
    {
        if(visited[nei] && recStack[nei])//cycle found
        {
            path.push_back(nei);
            return true;
        }
        else if(!visited[nei])
        {
            if(isValid(graph,nei,path,recStack,visited))
            {
                return true;
            }
        }
    }
    path.pop_back();
    recStack[node]=false;
    return false;
}

int main()
{
    int city,roads;
    cin>>city>>roads;
    unordered_map<int,vector<int>> graph;
    for(int i=0;i<roads;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    
    vector<int>path;
     vector<bool> visited(city+1,false);
     vector<bool> recStack(city+1,false);
    for(int i=1;i<=city;i++)
    {
       
        if(!visited[i]&& isValid(graph,i,path,recStack,visited))
        {
            int count=0;
            vector<int>result;
            int startNode=path.back();
            int idx=0;
            while(path[idx]!=startNode)
            {
                idx++;
            }
            for(int i=idx;i<path.size();i++)
            {
                result.push_back(path[i]);
                count++;
            }
            cout<<count<<endl;
            for(int node:result)
            {
                cout<<node<<" ";
            }
            cout<<endl;
            return 0;
        }
        
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}