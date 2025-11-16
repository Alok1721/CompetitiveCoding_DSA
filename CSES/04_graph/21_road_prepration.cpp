#include <bits/stdc++.h>
const int mod =1e9+7;
using namespace std;
typedef long long ll;

vector<ll> parent;
class DisjointSetUnion {
public:
    DisjointSetUnion(ll n) {
        parent.resize(n + 1);
        for (int i = 0; i <= n; ++i) {
            parent[i] = i;
        }
    }

    ll find(ll x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    bool unite(ll x, ll y) {
        ll rootX = find(x);
        ll rootY = find(y);
        if (rootX != rootY) {
            parent[rootY] = rootX; // Union by rank can be added here
            return true;
        }
        return false;
    }
};


int main()
{
    int t=1;
    // cin>> t;
    while(t--)
    {
       ll n,m;
       cin >> n >> m;  // number of city and roads
       DisjointSetUnion dsu(n);
       
       vector<vector<ll>> edges; // roads=(cost,first_city,second_city)
       for(int i = 0; i < m; ++i) {
            ll u, v, w;
            cin >> u >> v >> w;
            edges.push_back({w, u, v});
            edges.push_back({w, v, u}); 
       }
       sort(edges.begin(), edges.end());
         ll total_cost = 0;
         ll roads_used = 0;
       for(auto edge:edges)
       {
        if(dsu.unite(edge[1], edge[2])) {
            total_cost += edge[0];
            roads_used++;
        }
       }
         if(roads_used == n - 1) {
              cout << total_cost << endl; // Output the total cost of the minimum spanning tree
         } else {
              cout << "IMPOSSIBLE" << endl; // If not all cities are connected
         }
    }
    return 0;
}