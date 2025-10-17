#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> depth, parent;

// DFS to calculate depths
void dfs(int u, int p, int d) {
    depth[u] = d;
    parent[u] = p;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u, d + 1);
    }
}

// Function to check if we can reduce height to <= H with <= k reassignments
bool canReduce(int n, int H, int k) {
    // nodes deeper than H need fixing
    vector<pair<int,int>> nodes;
    for (int i = 2; i <= n; i++) {
        if (depth[i] > H) {
            nodes.push_back({depth[i], i});
        }
    }
    sort(nodes.rbegin(), nodes.rend()); // deepest first

    int used = 0;
    vector<bool> cut(n+1, false);

    for (auto &p : nodes) {
        int node = p.second;
        if (cut[node]) continue;
        // cut this whole subtree by reattaching this node to root
        used++;
        if (used > k) return false;
        // mark this subtree as handled
        queue<int> q;
        q.push(node);
        cut[node] = true;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (v == parent[u]) continue;
                if (!cut[v]) {
                    cut[v] = true;
                    q.push(v);
                }
            }
        }
    }
    return true;
}

int getMinimumHierarchyHeight(int hierarchy_nodes, vector<int> hierarchy_from,
                              vector<int> hierarchy_to, int max_reassignments) {
    int n = hierarchy_nodes;
    adj.assign(n+1, {});
    parent.assign(n+1, -1);
    depth.assign(n+1, 0);

    for (int i = 0; i < n-1; i++) {
        int u = hierarchy_from[i];
        int v = hierarchy_to[i];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // root at 1
    dfs(1, -1, 0);

    int lo = 1, hi = n, ans = n;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (canReduce(n, mid, max_reassignments)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> from(m), to(m);
    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i];
    }
    int k;
    cin >> k;

    cout << getMinimumHierarchyHeight(n, from, to, k) << "\n";
    return 0;
}