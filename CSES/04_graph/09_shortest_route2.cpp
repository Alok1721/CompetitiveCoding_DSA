#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 4e18;

int main()
{
    int n,m,q;
    cin>>n>>m>>q;
    unordered_map<int,vector<pair<int,int>>> graph;
    vector<vector<ll>> dist(n+1,vector<ll>(n+1,INF));
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        graph[a-1].push_back({b-1,c});
        graph[b-1].push_back({a-1,c});
        dist[a-1][b-1]=min(dist[a-1][b-1],(ll)c);
        dist[b-1][a-1]=min(dist[b-1][a-1],(ll)c);
    }
    
    
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                {
                    dist[i][j]=0;
                }
                if(dist[i][k]==INF || dist[k][j]==INF)continue;
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }


    for(int i=0;i<q;i++)
    {
        int s,d;
        cin>>s>>d;
        s--;d--;
        if(dist[s][d]!=INF)
        {
            cout<<dist[s][d]<<endl;
            continue;
        }else
        {
            cout<<-1<<endl;
        }
    }
    return 0;
}