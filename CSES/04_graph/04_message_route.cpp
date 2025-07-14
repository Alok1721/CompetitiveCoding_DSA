#include <bits/stdc++.h>
const int mod =1e9+7;
using namespace std;
typedef long long ll;




int main()
{
    int t=1;
    // cin>> t;
    while(t--)
    {
       int n,m;
       cin>>n>>m;

       vector<vector<int>>adj(n+1);
       vector<bool> visited(n+1,false);
       vector<int>parent(n+1,-1);
       for(int i=0;i<m;i++)
       {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
       }

       queue<int>q;
       q.push(1);
       visited[1]=true;

       while(!q.empty())
       {
        int u=q.front();
        q.pop();

        for(int v:adj[u])

        {
            if(!visited[v])
            {
                visited[v]=true;
                parent[v]=u;
                q.push(v);
            }
        }
    }

        if(!visited[n])
        {
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }

        vector<int> path;
        for(int cur=n;cur!=-1;cur=parent[cur])
        {
            path.push_back(cur);
        }

        reverse(path.begin(),path.end());

        cout<<path.size()<<endl;
        for(int node:path)
        {
            cout<<node<<" ";
        }
        cout<<endl;
       }
    
    return 0;
}