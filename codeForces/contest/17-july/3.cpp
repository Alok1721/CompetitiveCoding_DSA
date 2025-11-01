#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        k--; // Convert to 0-indexed
        
        vector<int> h(n);
        int max_height = 0;
        
        for (int i = 0; i < n; i++) {
            cin >> h[i];
            max_height = max(max_height, h[i]);
        }
        
        // Check if starting tower height is already <= initial water level
        if (h[k] <= 1) {
            cout << "NO\n";
            continue;
        }
        
        // Use Dijkstra's algorithm to find shortest time to reach any max height tower
        vector<long long> dist(n, LLONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        
        dist[k] = 0;
        pq.push({0, k});
        
        while (!pq.empty()) {
            long long d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            if (d > dist[u]) continue;
            
            // Try teleporting to all other towers
            for (int v = 0; v < n; v++) {
                if (v == u) continue;
                
                long long travel_time = abs(h[u] - h[v]);
                long long arrival_time = d + travel_time;
                
                // Check if we can survive the journey and at the destination
                // During the journey, we're on tower u, so water level must be <= h[u]
                // At arrival, water level will be (1 + arrival_time), must be <= h[v]
                if (d + travel_time < h[u] && arrival_time + 1 <= h[v]) {
                    if (arrival_time < dist[v]) {
                        dist[v] = arrival_time;
                        pq.push({arrival_time, v});
                    }
                }
            }
        }
        
        // Check if we can reach any tower with maximum height
        bool possible = false;
        for (int i = 0; i < n; i++) {
            if (h[i] == max_height && dist[i] != LLONG_MAX) {
                possible = true;
                break;
            }
        }
        
        cout << (possible ? "YES" : "NO") << "\n";
    }
    
    return 0;
}