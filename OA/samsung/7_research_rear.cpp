#include <bits/stdc++.h>
using namespace std;

int N, C;
vector<vector<int>> region;
vector<pair<int,int>> rareElements;

struct Node {
    int r, c, d;
};

int bfs(int sr, int sc) {
    vector<vector<int>> dist(N, vector<int>(N, -1));
    queue<Node> q;
    q.push({sr, sc, 0});
    dist[sr][sc] = 0;

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    while(!q.empty()) {
        auto [r, c, d] = q.front(); q.pop();
        for(int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if(nr >= 0 && nr < N && nc >= 0 && nc < N && region[nr][nc] == 1 && dist[nr][nc] == -1) {
                dist[nr][nc] = d + 1;
                q.push({nr, nc, d + 1});
            }
        }
    }

    // Compute maximum distance from this cell to all rare elements
    int maxDist = 0;
    for(auto [x, y] : rareElements) {
        if(dist[x][y] == -1) return INT_MAX; // unreachable
        maxDist = max(maxDist, dist[x][y]);
    }
    return maxDist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        cin >> N >> C;
        rareElements.clear();
        region.assign(N, vector<int>(N, 0));

        for(int i = 0; i < C; i++) {
            int x, y;
            cin >> x >> y;
            rareElements.push_back({x-1, y-1}); // convert to 0-based index
        }

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cin >> region[i][j];
            }
        }

        int ans = INT_MAX;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(region[i][j] == 1) {
                    ans = min(ans, bfs(i, j));
                }
            }
        }

        cout << ans << "\n";
    
    return 0;
}
