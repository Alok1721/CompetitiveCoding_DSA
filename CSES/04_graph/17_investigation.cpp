#include <bits/stdc++.h>
const int mod =1e9+7;
using namespace std;
typedef long long ll;
const ll INF = 1e18;



int main()
{
    int t=1;
    // cin>> t;
    while(t--)
    {
       unordered_map<int, vector<pair<int,int>>> adj; //u->(v,flight cost)
         int n, m;
         cin >> n >> m;  // number of nodes and edges
            for (int i = 0; i < m; ++i) {
                int u, v, w;
                cin >> u >> v >> w;
                adj[u].push_back({v, w});
            }
            int source = 1; // Assuming source is node 1
            int target = n; // Assuming target is node n

            vector<ll> dist(n + 1, INF);//calculate minimum price to reach destination
            vector<int>ways(n + 1, 0),min_flights(n+1,INT_MAX),max_flights(n+1,0); //calculate number of ways to reach destination
            ways[source] = 1;
            min_flights[source] = 0; //minimum flights to reach destination
            max_flights[source] = 0; //maximum flights to reach destination
            priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq; //min heap
            // queue<int>pq;
            pq.push({0,source});
            dist[source] = 0;
            while (!pq.empty()) {
                ll cost = pq.top().first;
                int node= pq.top().second;
                pq.pop();
                if (cost > dist[node]) continue; //if cost is greater than the minimum cost to reach node, skip it
                for (auto flight: adj[node]) {
                    int v = flight.first;
                    int w = flight.second;
                    if (dist[node] + w < dist[v]) {
                        dist[v] = dist[node] + w;
                        ways[v] = ways[node];
                        min_flights[v] = min_flights[node] + 1;
                        max_flights[v] = max_flights[node] + 1;
                        pq.push({dist[v], v});
                    } else if (dist[node] + w == dist[v]) {
                        ways[v] = (ways[v] + ways[node]) % mod;
                        min_flights[v] = min(min_flights[v], min_flights[node] + 1);
                        max_flights[v] = max(max_flights[v], max_flights[node] +1);
                    }
                        
                    }
                
            }
            cout<< (dist[target] == INF ? -1 : dist[target]) <<" "<<ways[n]<< " "<<min_flights[n]<<" "<<max_flights[n] << endl;
             
    }
    return 0;
}