#include <bits/stdc++.h>
using namespace std;

int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

// BFS function outside
int bfs(int si, int sj, vector<vector<int>> &A, vector<vector<bool>> &visited, int N, int M) {
    queue<pair<int,int>> q;
    q.push({si, sj});
    visited[si][sj] = true;
    int size = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        size++;

        for (auto &d : dirs) {
            int nx = x + d[0], ny = y + d[1];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M &&
                !visited[nx][ny] && A[nx][ny] == 1) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return size;
}

int maxScore(int N, int M, int *Aptr) {
    vector<vector<int>> A(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            A[i][j] = *((Aptr + i * M) + j);
        }
    }

    vector<vector<bool>> visited(N, vector<bool>(M, false));
    vector<int> clusterSizes;

    // find all clusters
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] == 1 && !visited[i][j]) {
                clusterSizes.push_back(bfs(i, j, A, visited, N, M));
            }
        }
    }

    // sort descending
    sort(clusterSizes.rbegin(), clusterSizes.rend());

    // Barry gets sum of even-indexed clusters
    int result = 0;
    for (int i = 0; i < (int)clusterSizes.size(); i += 2) {
        result += clusterSizes[i];
    }

    return result;
}

int main() {
    int N, M;
    cin >> N >> M;
    int *Aptr = new int[N * M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> *((Aptr + i * M) + j);
        }
    }

    cout << maxScore(N, M, Aptr) << endl;
    delete[] Aptr;
    return 0;
}
