#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 105;

// Graph for DFS and bridge finding
vector<vector<pair<int, int>>> graph;
vector<int> tin, low;
vector<bool> visited;
set<string> bridges;
int timer;

// Edges for MST
vector<tuple<int, int, int>> edges;
vector<int> parent, rank_ds;

// Generate edge key for undirected edge
string edgeKey(int u, int v) {
    return to_string(min(u, v)) + "-" + to_string(max(u, v));
}

// DFS to find bridges using Tarjan's algorithm
void dfsBridge(int u, int par) {
    visited[u] = true;
    tin[u] = low[u] = ++timer;
    
    for (auto [v, w] : graph[u]) {
        if (v == par) continue;
        if (visited[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            dfsBridge(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u]) {
                bridges.insert(edgeKey(u, v));
            }
        }
    }
}

// DFS to find connected components excluding bridges
void dfsComponent(int u, vector<bool>& vis, vector<int>& component) {
    vis[u] = true;
    component.push_back(u);
    for (auto [v, w] : graph[u]) {
        if (!vis[v] && bridges.find(edgeKey(u, v)) == bridges.end()) {
            dfsComponent(v, vis, component);
        }
    }
}

// Disjoint Set Union for Kruskal's algorithm
int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (rank_ds[x] < rank_ds[y]) swap(x, y);
    parent[y] = x;
    if (rank_ds[x] == rank_ds[y]) rank_ds[x]++;
}

int getCheapestResult(int n, int k, int arr[][3]) {
    // Step 1: Build the graph
    graph.assign(n, vector<pair<int, int>>());
    edges.clear();
    for (int i = 0; i < k; i++) {
        int u = arr[i][0], v = arr[i][1], w = arr[i][2];
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
        edges.emplace_back(w, u, v);
    }
    
    // Step 2: Find bridges
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    bridges.clear();
    timer = 0;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfsBridge(i, -1);
        }
    }
    
    // Step 3: Find the largest connected component
    visited.assign(n, false);
    vector<int> largestComponent;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            vector<int> component;
            dfsComponent(i, visited, component);
            if (component.size() > largestComponent.size()) {
                largestComponent = component;
            }
        }
    }
    
    set<int> validNodes(largestComponent.begin(), largestComponent.end());
    
    // Step 4: Kruskal's MST on the valid component
    vector<tuple<int, int, int>> validEdges;
    for (auto [w, u, v] : edges) {
        if (validNodes.count(u) && validNodes.count(v) && 
            bridges.find(edgeKey(u, v)) == bridges.end()) {
            validEdges.emplace_back(w, u, v);
        }
    }
    
    sort(validEdges.begin(), validEdges.end());
    
    parent.resize(n);
    rank_ds.assign(n, 0);
    for (int i = 0; i < n; i++) parent[i] = i;
    
    int result = 0;
    for (auto [w, u, v] : validEdges) {
        int pu = find(u), pv = find(v);
        if (pu != pv) {
            unite(pu, pv);
            result += w;
        }
    }
    
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    
    int arr[MAXN][3];
    for (int i = 0; i < k; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    
    cout << getCheapestResult(n, k, arr) << '\n';
    
    return 0;
}