#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9; // A large value representing "infinity"

void floydWarshall(vector<vector<int>>& dist, int n) {
    // dist[i][j] initially should contain:
    // - weight of edge i->j if it exists
    // - 0 if i == j
    // - INF if no direct edge

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}
