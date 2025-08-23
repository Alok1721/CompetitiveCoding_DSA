#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<vector<int>> &g, vector<bool> &vis) {
    vis[u] = true;
    for (auto v : g[u])
        if (!vis[v]) dfs(v, g, vis);
}

bool canFormClosedLoop(vector<string> &words) {
    vector<vector<int>> g(26), gr(26); // graph and reverse graph
    vector<int> in(26, 0), out(26, 0);

    for (auto &w : words) {
        int u = w.front() - 'a';
        int v = w.back() - 'a';
        g[u].push_back(v);
        gr[v].push_back(u);
        out[u]++;
        in[v]++;
    }

    // 1. In-degree == Out-degree for all used vertices
    for (int i = 0; i < 26; i++) {
        if (in[i] != out[i]) return false;
    }

    vector<bool>vis(26,false);
    for(int i=0;i<26;i++)
    {
        if(!vis[i])
        {
            dfs(i,g,vis);
        }
    }
    for(int i=0;i<26;i++)
    {
        if(!vis[i])
        {
            return false;
        }
    }

    

    return true;
}

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++) cin >> words[i];
    cout << (canFormClosedLoop(words) ? "YES" : "NO") << "\n";
}
