#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int N, M;
        cin >> N >> M;

        vector<vector<int>> city(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> city[i][j];

        int br, bc;
        cin >> br >> bc;
        br--, bc--;               // convert to 0-index

        vector<vector<int>> dist(N, vector<int>(M, -1));
        queue<pair<int,int>> q;

        // If bomb drops on empty cell, no spread happens
        if (city[br][bc] == 1) {
            dist[br][bc] = 0;
            q.push({br, bc});
        }

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        int answer = 0;

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
                if (city[nr][nc] == 0) continue;
                if (dist[nr][nc] != -1) continue;

                dist[nr][nc] = dist[r][c] + 1;
                answer = max(answer, dist[nr][nc]);
                q.push({nr, nc});
            }
        }

        cout << "Case #" << tc << "\n\n";
        cout << answer << "\n\n";
    }

    return 0;
}
