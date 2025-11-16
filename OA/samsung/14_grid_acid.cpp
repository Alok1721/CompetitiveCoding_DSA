#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    const int INF = 1000000000;
    for (int tc = 1; tc <= T; ++tc) {
        int N, M;
        cin >> N >> M;
        int sr, sc;
        cin >> sr >> sc;
        // Input gives 1-based indices -> convert to 0-based
        --sr; --sc;

        vector<int> grid(N * M);
        int type2_r = -1, type2_c = -1;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                int v; cin >> v;
                grid[i * M + j] = v;
                if (v == 2) { type2_r = i; type2_c = j; }
            }
        }

        auto inside = [&](int r, int c) {
            return r >= 0 && r < N && c >= 0 && c < M;
        };

        // Directions
        const int dr[4] = {-1, 1, 0, 0};
        const int dc[4] = {0, 0, -1, 1};

        // BFS1: distances over type1 cells only (treat type2 and type0 as blocked)
        vector<int> dist1(N * M, INF);
        queue<int> q;
        int sidx = sr * M + sc;
        if (grid[sidx] == 1) {
            dist1[sidx] = 0;
            q.push(sidx);
        } else {
            // As per problem guaranteed source is type 1, but be safe
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            int ur = u / M, uc = u % M;
            int ud = dist1[u];
            for (int k = 0; k < 4; ++k) {
                int vr = ur + dr[k], vc = uc + dc[k];
                if (!inside(vr, vc)) continue;
                int v = vr * M + vc;
                if (grid[v] != 1) continue; // only traverse type1
                if (dist1[v] == INF) {
                    dist1[v] = ud + 1;
                    q.push(v);
                }
            }
        }

        long long Count1 = -1, Count2 = -1;
        // Check if type2 can be filled.
        bool canFillType2 = true;
        if (type2_r == -1) {
            // Shouldn't happen per statement, but handle
            canFillType2 = false;
        } else {
            // Must have all 4 neighbours inside grid and reachable (and not stone)
            int r2 = type2_r, c2 = type2_c;
            int neighArr[4];
            for (int k = 0; k < 4; ++k) {
                int nr = r2 + dr[k], nc = c2 + dc[k];
                if (!inside(nr, nc)) {
                    canFillType2 = false;
                    break;
                }
                int ni = nr * M + nc;
                if (grid[ni] == 0) { // stone cannot be in contact
                    canFillType2 = false;
                    break;
                }
                // neighbour must be reachable without passing through type2 (we blocked type2 in BFS1)
                if (grid[ni] == 1 && dist1[ni] == INF) {
                    canFillType2 = false;
                    break;
                }
                // If neighbour is type2 (shouldn't happen, only one type2), treat as impossible
                if (grid[ni] == 2) {
                    canFillType2 = false;
                    break;
                }
                // arrival time for neighbour: if it's type1, dist1; if it's the source and was type1 dist1 is set
                neighArr[k] = dist1[ni];
            }
            if (!canFillType2) {
                Count1 = -1;
                Count2 = -1;
            } else {
                // Earliest time when all four neighbours are in contact is the max of their arrival times.
                int mx = 0;
                for (int k = 0; k < 4; ++k) mx = max(mx, neighArr[k]);
                Count1 = mx;
                // Now do Dijkstra-like propagation allowing entering type2 only at time >= Count1.
                // Distances are arrival times (time when acid enters that cell).
                vector<int> dist2(N * M, INF);
                using P = pair<int,int>;
                priority_queue<P, vector<P>, greater<P>> pq;
                dist2[sidx] = 0;
                pq.emplace(0, sidx);
                while (!pq.empty()) {
                    auto [t, u] = pq.top(); pq.pop();
                    if (t != dist2[u]) continue;
                    int ur = u / M, uc = u % M;
                    for (int k = 0; k < 4; ++k) {
                        int vr = ur + dr[k], vc = uc + dc[k];
                        if (!inside(vr, vc)) continue;
                        int v = vr * M + vc;
                        if (grid[v] == 0) continue; // stone
                        int cand;
                        if (grid[v] == 2) {
                            // can enter v only when both u has leaked (t+1) and Count1 has been reached
                            cand = max(t + 1, (int)Count1);
                        } else { // type1
                            cand = t + 1;
                        }
                        if (cand < dist2[v]) {
                            dist2[v] = cand;
                            pq.emplace(cand, v);
                        }
                    }
                }
                // compute Count2: maximum arrival time among all non-stone cells (type1 and type2).
                int maxArrival = 0;
                bool allReached = true;
                for (int i = 0; i < N*M; ++i) {
                    if (grid[i] == 0) continue; // ignore stones
                    if (dist2[i] == INF) { allReached = false; break; }
                    if (dist2[i] > maxArrival) maxArrival = dist2[i];
                }
                if (!allReached) {
                    Count2 = -1;
                    // If type2 couldn't be filled earlier we'd have set -1 already; but by problem note: if type2 not filled -> Count2=-1
                    // Here type2 was fillable, but still some other non-stone unreachable -> Count2=-1.
                    // As per note 2: if empty cell cannot be filled then #1 and #2 are -1; we've handled that earlier.
                } else {
                    Count2 = maxArrival;
                }
            }
        }

        // Output
        cout << "Case #" << tc << "\n";
        cout << Count1 << " " << Count2 << "\n";
    }

    return 0;
}
