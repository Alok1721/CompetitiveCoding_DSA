#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main() {
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> edges(m);
    vector<vector<int>> adj(n + 1), rev(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, -w}; // We negate weight to find longest path
        adj[u].push_back(v);   // For reachability
        rev[v].push_back(u);   // For back reachability
    }

    // Step 1: DFS from src and to dest to find reachable nodes
    vector<bool> vis1(n + 1, false), vis2(n + 1, false);
    function<void(int, vector<vector<int>>&, vector<bool>&)> dfs = [&](int u, vector<vector<int>>& graph, vector<bool>& vis) {
        vis[u] = true;
        for (int v : graph[u]) {
            if (!vis[v]) dfs(v, graph, vis);
        }
    };

    dfs(1, adj, vis1);      // Reachable from source
    dfs(n, rev, vis2);      // Can reach destination (reverse graph)

    // Step 2: Bellman-Ford
    vector<ll> dist(n + 1, INF);
    dist[1] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (auto [u, v, w] : edges) {
            if (dist[u] < INF && dist[v] > dist[u] + w)
                dist[v] = dist[u] + w;
        }
    }

    // Step 3: Detect negative cycle that is on the path from src to dest
    for (auto [u, v, w] : edges) {
        if (dist[u] < INF && dist[v] > dist[u] + w) {
            if (vis1[u] && vis2[v]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << -dist[n] << endl; // Negate to convert back to max path
    return 0;
}
