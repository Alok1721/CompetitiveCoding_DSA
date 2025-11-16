#include <bits/stdc++.h>
const int mod =1e9+7;
using namespace std;
typedef long long ll;

void topoSort(int node, unordered_map<int, vector<int>>& adj, vector<int>& vis, stack<int>& st) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        int v = it;
        if (!vis[v]) {
            topoSort(v, adj, vis, st);
        }
    }
    st.push(node);
}


int main()
{
    int t=1;
    // cin>> t;
    while(t--)
    {
       int n,m;
       cin >> n >> m;  // number of nodes and edges
       unordered_map<int,vector<int>>adj;
       for(int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
       }
         int source = 1; // Assuming source is node 1
            int target = n; // Assuming target is node n
            vector<int>ways(n + 1, 0);
            stack<int> st;
            vector<int> vis(n + 1, 0);
            for (int i = 1; i <= n; ++i) {
                if (!vis[i]) {
                    topoSort(i, adj, vis, st);
                }
            }
            ways[source] = 1;
            while (!st.empty()) {
                int node = st.top();
                st.pop();

                    for (int v : adj[node]) {
                        ways[v] = (ways[v] + ways[node]) % mod;
                    //     if (v == target) {
                    //         cout<< ways[v] << endl; // Output the number of ways to reach target
                    //         return 0;
                        
                    // }
                }
            }
            cout<< ways[n] << endl; // If target is unreachable
    }
    return 0;
}