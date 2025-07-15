#include <bits/stdc++.h>
const int mod =1e9+7;
using namespace std;
typedef long long ll;
vector<vector<ll>>floydWarshall(int n,const vector<tuple<int,int,ll>>& edges)
{
    vector<vector<ll>>dist(n+1,vector<ll>(n+1,LLONG_MAX);

    for(int i=1;i<=n;i++)
        dist[i][i]=0;
)
    for(auto edge:edges)
    {
        int a=get<0>(edge);
        int b=get<1>(edge);
        int c=get<2>(edge);
        dist[a][b]=min(dist[a][b],c);
        dist[b][a]=min(dist[b][a],c);
    }

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(dis[i][k]+dist[k][j]<dist[i][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
    return dist;


}




int main()
{
    int t=1;
    // cin>> t;
    while(t--)
    {
        int n,m,q;
        cin>>n>>m>>q;
        vector<tuple<int,int,ll>>edges;
        for(int i=0;i<m;i++)
        {
            int a,b;
            ll c;
            cin>>a>>b>>c;
            edges.push_back({a, b, c});
        }
       
        vector<vector<ll>>dist=floydWarshall(n, edges);
        for(int i=0;i<q;i++)
        {
            int a,b;
            cin>>a>>b;
            if(dist[a][b] == LLONG_MAX)
                cout << "-1\n";
            else
                cout << dist[a][b] << "\n";
        }
    }
    return 0;
}