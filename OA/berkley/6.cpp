#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    int cost;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numZones;
    cin >> numZones;

    int numRoads, constX;
    cin >> numRoads >> constX; // constX is always 3

    vector<vector<Edge>> graph(numZones + 1);

    for (int i = 0; i < numRoads; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    int numComplaints, constY;
    cin >> numComplaints >> constY; // constY is always 2

    vector<pair<int, int>> complaints(numComplaints);
    for (int i = 0; i < numComplaints; i++) {
        cin >> complaints[i].first >> complaints[i].second;
    }

    // Dijkstra from zone 1
    const long long INF = 1e15;
    vector<long long> dist(numZones + 1, INF);
    dist[1] = 0;

    using P = pair<long long, int>; // (dist, node)
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;
        for (auto &edge : graph[u]) {
            if (dist[edge.to] > d + edge.cost) {
                dist[edge.to] = d + edge.cost;
                pq.push({dist[edge.to], edge.to});
            }
        }
    }

    // Answer each complaint
    for (int i = 0; i < numComplaints; i++) {
        int zoneX = complaints[i].first;
        int timeK = complaints[i].second;

        long long travelTime = dist[zoneX] * 2; // go and return
        if (travelTime <= timeK) {
            cout << (timeK - travelTime);
        } else {
            cout << 0;
        }
        if (i != numComplaints - 1) cout << " ";
    }
    cout << "\n";

    return 0;
}
