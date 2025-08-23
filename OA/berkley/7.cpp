#include <bits/stdc++.h>
using namespace std;

// Function to perform BFS and find the maximum distance from a source node to any other engineer
int maxDistanceToEngineer(int src, const vector<vector<int>>& adj, const vector<int>& engineers) {
    vector<int> dist(adj.size(), -1);
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    int max_dist = 0;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) { // Not visited
                dist[v] = dist[u] + 1;
                q.push(v);
                // Check if v is an engineer (in engineers list)
                if (find(engineers.begin(), engineers.end(), v) != engineers.end()) {
                    max_dist = max(max_dist, dist[v]);
                }
            }
        }
    }
    return max_dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // Read input string
    string inputString;
    cin >> inputString;
    int len = inputString.size();
    
    // Step 1: Identify engineer nodes ('1') and build adjacency list
    vector<int> engineers; // Store indices of nodes with '1'
    for (int i = 0; i < len; i++) {
        if (inputString[i] == '1') {
            engineers.push_back(i);
        }
    }
    
    // Build adjacency list (undirected graph)
    vector<vector<int>> adj(len);
    for (int i = 0; i < len; i++) {
        if (inputString[i] == '1') {
            // Left child at 2*i + 1
            int left = 2 * i + 1;
            if (left < len && inputString[left] == '1') {
                adj[i].push_back(left);
                adj[left].push_back(i);
            }
            // Right child at 2*i + 2
            int right = 2 * i + 2;
            if (right < len && inputString[right] == '1') {
                adj[i].push_back(right);
                adj[right].push_back(i);
            }
        }
    }
    
    // Step 2: For each engineer, compute max distance to any other engineer
    vector<int> result;
    for (int u : engineers) {
        int max_dist = maxDistanceToEngineer(u, adj, engineers);
        result.push_back(max_dist);
    }
    
    // Step 3: Output results
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << " ";
    }
    cout << endl;
    
    return 0;
}