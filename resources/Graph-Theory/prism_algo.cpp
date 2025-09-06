#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find sum of weights of edges of MST using Prim's algorithm.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // Min heap {weight, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        vector<int> visited(V, 0);
        int sum = 0;

        // Start from node 0
        pq.push({0, 0});
        
        while(!pq.empty()) {
            auto [wt, node] = pq.top();
            pq.pop();

            if(visited[node]) continue;

            // Add edge weight to MST
            visited[node] = 1;
            sum += wt;

            // Push adjacent edges
            for(auto &it : adj[node]) {
                int adjNode = it[0];
                int edgeWt = it[1];
                if(!visited[adjNode]) {
                    pq.push({edgeWt, adjNode});
                }
            }
        }
        return sum;
    }
};

int main() {
    int V = 5; // vertices
    vector<vector<int>> adj[V];

    // Example graph edges (u, v, w)
    vector<tuple<int,int,int>> edges = {
        {0,1,2}, {0,3,6}, {1,2,3}, {1,3,8}, {1,4,5}, {2,4,7}, {3,4,9}
    };

    // Undirected graph -> push both ways
    for(auto [u,v,w] : edges) {
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    Solution obj;
    cout << "Weight of MST: " << obj.spanningTree(V, adj) << endl;

    return 0;
}
