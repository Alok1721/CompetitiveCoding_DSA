#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// K Shortest Paths (works for graphs with cycles)
void kShortestPaths(int n, int m, int k, vector<vector<pair<int, ll>>>& graph) {
    vector<vector<ll>> dist(n);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;

    pq.push({0, 0}); // {distance, node}

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (dist[u].size() >= k) continue; // already found k shortest paths for this node
        dist[u].push_back(d);

        for (auto [v, w] : graph[u]) {
            ll nd = d + w;
            pq.push({nd, v});
        }
    }

    // Print k shortest paths to node n-1
    if (dist[n-1].empty()) {
        cout << "-1\n";
        return;
    }

    for (ll x : dist[n-1]) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, ll>>> graph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        graph[u - 1].push_back({v - 1, w});
    }

    kShortestPaths(n, m, k, graph);
    return 0;
}
