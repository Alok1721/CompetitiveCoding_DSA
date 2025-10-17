#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int N;
vector<vector<pair<int,int>>> adj;
vector<long long> xorDist;

void dfs(int u, int p, long long val) {
    xorDist[u] = val;
    for (auto [v, w] : adj[u]) {
        if (v == p) continue;
        dfs(v, u, val ^ w);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    adj.assign(N+1, {});
    xorDist.assign(N+1, 0);

    for (int i = 0; i < N-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // root at 1
    dfs(1, -1, 0);

    long long ans = 0;
    for (int bit = 0; bit < 60; bit++) { // up to 1e9 fits in 30 bits, but safer with 60
        long long cnt1 = 0;
        for (int i = 1; i <= N; i++) {
            if (xorDist[i] & (1LL << bit)) cnt1++;
        }
        long long cnt0 = N - cnt1;
        long long contrib = (cnt1 * cnt0) % MOD;
        contrib = (contrib * ((1LL << bit) % MOD)) % MOD;
        ans = (ans + contrib) % MOD;
    }

    cout << ans << "\n";
    return 0;
}
