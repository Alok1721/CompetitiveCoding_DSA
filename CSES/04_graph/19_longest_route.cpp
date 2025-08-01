#include <bits/stdc++.h>
const int mod =1e9+7;
using namespace std;
typedef long long ll;
    void topoSort(int node,unordered_map<int,vector<int>>&adj,vector<int>&vis,stack<int>&st)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            int v=it;
            if(!vis[v])
            {
                topoSort(v,adj,vis,st);
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
       int n, m;
       cin >> n >> m;  // number of nodes and edges
       unordered_map<int,vector<int>>adj;
         for (int i = 0; i < m; ++i) {
              int u, v;
              cin >> u >> v;
              adj[u].push_back(v);
         }
         
         int source=1;
         int target=n;
         vector<int> dist(n + 1, INT_MIN);
         vector<int> parent(n + 1, -1);
         stack<int> st;
         vector<int> vis(n + 1, 0);
            for (int i = 1; i <= n; ++i) {
                if (!vis[i]) {
                    topoSort(i, adj, vis, st);
                }
            }
            dist[source] = 1;
            parent[source] = -1;
            while (!st.empty()) {
                int node = st.top();
                st.pop();
                if (dist[node] != INT_MIN) {
                    for (int v : adj[node]) {
                        if (dist[node] + 1 > dist[v]) {
                            dist[v] = dist[node] + 1;
                            parent[v] = node;
                        }
                    }
                }
            }
            int total_distance = dist[target]; // Assuming target is node n
            if (total_distance == INT_MIN) {
                cout<<"IMPOSSIBLE"<<endl;
            } else {
                cout << total_distance << endl;
                vector<int> path;
                for (int v = target; v != -1; v = parent[v]) {
                    path.push_back(v);
                }
                reverse(path.begin(), path.end());
                for (int v : path) {
                    cout << v << " ";
                }
                cout << endl;
            }
    }
    return 0;
}