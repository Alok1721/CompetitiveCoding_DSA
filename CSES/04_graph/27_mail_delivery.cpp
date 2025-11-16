#include <bits/stdc++.h>
using namespace std;

void dfsEuler(int node, unordered_map<int, multiset<int>>& graph, vector<int>& path) {
    // recursive Hierholzer’s algorithm
    while (!graph[node].empty()) {
        int next = *graph[node].begin();
        graph[node].erase(graph[node].begin());
        graph[next].erase(graph[next].find(node));
        dfsEuler(next, graph, path);
    }
    path.push_back(node);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    unordered_map<int, multiset<int>> graph;
    vector<int> degree(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
        degree[a]++;
        degree[b]++;
    }

    // (1) Check if all degrees are even
    for (int i = 1; i <= n; i++) {
        if (degree[i] % 2) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    // (2) Check connectivity of the graph (only among nodes with degree > 0)
    vector<int> vis(n + 1, 0);
    function<void(int)> dfs = [&](int node) {
        vis[node] = 1;
        for (int nei : graph[node]) {
            if (!vis[nei]) dfs(nei);
        }
    };

    int start = 1;
    // find first vertex with degree > 0
    while (start <= n && degree[start] == 0) start++;
    if (start > n) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    dfs(start);

    for (int i = 1; i <= n; i++) {
        if (degree[i] > 0 && !vis[i]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    // (3) Build Euler circuit
    vector<int> path;
    dfsEuler(1, graph, path);

    if ((int)path.size() != m + 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    // (4) Print the path in correct order
    reverse(path.begin(), path.end());
    for (int v : path) cout << v << " ";
    cout << "\n";

    return 0;
}
