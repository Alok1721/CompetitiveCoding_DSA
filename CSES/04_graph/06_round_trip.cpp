#include<bits/stdc++.h>
using namespace std;
bool isValid(unordered_map<int,vector<int>>&graph,int node,vector<int>&path,int parent,vector<bool>& visited)
{

    visited[node]=true;
    path.push_back(node);
    for(auto nei:graph[node])
    {
        if(nei==parent )continue;
        if(visited[nei] && nei!=parent)//cycle found
        {
            path.push_back(nei);
            return true;
        }
        else if(!visited[nei])
        {
            if(isValid(graph,nei,path,node,visited))
            {
                return true;
            }
        }
    }
    path.pop_back();
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
        graph[b].push_back(a);
    }
    
    vector<int>path;
     vector<bool> visited(city+1,false);
    for(int i=1;i<=city;i++)
    {
       
        if(!visited[i]&& isValid(graph,i,path,-1,visited))
        {
            int count=0;
            vector<int>result;
            int startNode=path.back();
            for(int i=path.size()-1;i>=0;i--)
            {
                result.push_back(path[i]);
                count++;
                if(path[i]==startNode && i!=path.size()-1)
                    break;
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