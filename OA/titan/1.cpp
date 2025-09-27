#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;
long long r = 0;
int n;
int a[N];
int f[N][2];
vector<int> adj[N];

// DFS to calculate contribution of each bit
void dfs(int u, int p, int k) {
    int w = (a[u] >> k) & 1;

    f[u][w] = 1;
    f[u][w ^ 1] = 0;

    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u, k);
        r += 1LL * f[v][0] * f[u][1] + 1LL * f[v][1] * f[u][0];
        r <<= k; // multiply by 2^k
        f[u][1] += f[v][w ^ 1];
        f[u][0] += f[v][w];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        r += a[i];  // initial sum of single nodes
    }

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int k = 19; k >= 0; --k) {
        dfs(1, 0, k);
    }

    cout << r << "\n";
    return 0;
}
