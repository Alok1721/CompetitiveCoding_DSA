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

        vector<vector<pair<int,ll>>> adj(n+1);

        for(int i=0;i<m;i++)
        {
            int a,b;
            ll c;
            cin>>a>>b>>c;
            adj[a].push_back({b,c});
        }

        vector<ll> dist(n+1, LLONG_MAX);
        dist[1]=0;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        pq.push({0, 1});
        
        while(!pq.empty())
        {
            auto curr=pq.top();
            int d=curr.first;
            int u=curr.second;
            pq.pop();

            if(d>dist[u])continue;

            for(auto nei:adj[u])
            {
                int v=nei.first;
                ll w=nei.second;

                if(dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==LLONG_MAX)
                cout<<"-1 ";
            else
                cout<<dist[i]<<" ";
        }

    }

    
    return 0;
}