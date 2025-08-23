#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<int> w;
vector<vector<int>> adj;
long long ans = 0;
unordered_map<int,int> freq;

void dfs(int u, int parent, int curXor) {
    curXor^=w[u];
    // if(curXor==x)ans++;
    ans+=freq[curXor^x];
    freq[curXor]++;
    for(auto it:adj[u])
    {
        if(it==parent)continue;
        dfs(it,u,curXor);
    }
    freq[curXor]--;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    w.resize(n);
    for (int i = 0; i < n; i++) cin >> w[i];
    adj.assign(n, {});
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v; // zero-based indexing
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    cin >> x;
    
    dfs(0, -1, 0);
    
    cout << ans << "\n";
}
