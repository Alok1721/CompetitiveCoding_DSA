#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int node, int parent, vector<int> adj[], vector<int>& visited) {
        visited[node] = 1;

        for (int neigh : adj[node]) {
            if (!visited[neigh]) {
                if (dfs(neigh, node, adj, visited)) return true;
            }
            // If neighbor is visited and not parent -> cycle
            else if (neigh != parent) {
                return true;
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, -1, adj, visited)) return true;
            }
        }
        return false;
    }
};

// ---------------- Driver ----------------
int main() {
    int V = 5;
    vector<int> adj[V];

    // Example graph: edges
    // 0-1, 1-2, 2-0 (cycle), 3-4
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(0);
    adj[0].push_back(2);

    adj[3].push_back(4);
    adj[4].push_back(3);

    Solution obj;
    if (obj.isCycle(V, adj))
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";

    return 0;
}
