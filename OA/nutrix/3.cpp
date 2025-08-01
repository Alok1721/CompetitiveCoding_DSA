#include <vector>
#include <climits>
#include <iostream>

using namespace std;

long long getMinimumTime(int connection_nodes, vector<int> connection_from, vector<int> connection_to, 
                        vector<int> connection_cost, vector<int> deliveries) {
    int n = connection_nodes;
    int m = connection_from.size();
    int k = deliveries.size();
    
    // Create adjacency matrix
    vector<vector<long long>> dist(n, vector<long long>(n, LLONG_MAX));
    for (int i = 0; i < n; i++) dist[i][i] = 0;
    
    // Fill adjacency matrix with road costs
    for (int i = 0; i < m; i++) {
        int u = connection_from[i];
        int v = connection_to[i];
        long long w = connection_cost[i];
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }
    
    // Floyd-Warshall to find shortest paths between all pairs
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    
    // Check if all delivery points are reachable from 0
    for (int d : deliveries) {
        if (dist[0][d] == LLONG_MAX) return -1;
    }
    
    // DP with bitmask
    vector<vector<long long>> dp(1 << k, vector<long long>(k + 1, LLONG_MAX));
    // Initialize: starting from junction 0 to each delivery point
    for (int i = 0; i < k; i++) {
        dp[1 << i][i] = dist[0][deliveries[i]];
    }
    
    // For each subset of visited deliveries
    for (int mask = 1; mask < (1 << k); mask++) {
        for (int last = 0; last < k; last++) {
            if (!(mask & (1 << last))) continue;
            if (dp[mask][last] == LLONG_MAX) continue;
            
            // Try visiting each unvisited delivery point
            for (int next = 0; next < k; next++) {
                if (mask & (1 << next)) continue;
                int new_mask = mask | (1 << next);
                if (dist[deliveries[last]][deliveries[next]] != LLONG_MAX) {
                    dp[new_mask][next] = min(dp[new_mask][next], 
                                          dp[mask][last] + dist[deliveries[last]][deliveries[next]]);
                }
            }
        }
    }
    
    // Find minimum time to visit all deliveries and return to 0
    long long result = LLONG_MAX;
    int full_mask = (1 << k) - 1;
    for (int last = 0; last < k; last++) {
        if (dp[full_mask][last] != LLONG_MAX && dist[deliveries[last]][0] != LLONG_MAX) {
            result = min(result, dp[full_mask][last] + dist[deliveries[last]][0]);
        }
    }
    
    return result == LLONG_MAX ? -1 : result;
}

int main() {
    int connection_nodes, m;
    
    // Read number of junctions and roads
    cin >> connection_nodes >> m;
    
    vector<int> connection_from(m), connection_to(m), connection_cost(m);
    
    // Read road connections and costs
    for (int i = 0; i < m; i++) {
        cin >> connection_from[i] >> connection_to[i] >> connection_cost[i];
    }
    
    // Read number of deliveries
    int k;
    cin >> k;
    
    vector<int> deliveries(k);
    
    // Read delivery locations
    for (int i = 0; i < k; i++) {
        cin >> deliveries[i];
    }
    
    // Calculate and output the result
    long long result = getMinimumTime(connection_nodes, connection_from, connection_to, connection_cost, deliveries);
    cout << result << endl;
    
    return 0;
}