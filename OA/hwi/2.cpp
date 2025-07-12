#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> A;
map<tuple<int, int, int, int, bool>, bool> dp;
vector<pair<int, int>> dirs = {{1, 0}, {0, 1}};

bool dfs(int ax, int ay, int bx, int by, bool turn) {
    auto key = make_tuple(ax, ay, bx, by, turn);
    if (dp.count(key)) return dp[key];

    if (turn) { // Alice's turn
        bool can_win = false;
        for (auto [dx, dy] : dirs) {
            int nx = ax + dx, ny = ay + dy;
            if (nx < N && ny < M && A[nx][ny] >= A[bx][by]) {
                if (dfs(nx, ny, bx, by, !turn)) {
                    can_win = true;
                    break;
                }
            }
        }
        return dp[key] = can_win;
    } else { // Bob's turn
        bool opponent_loses = true;
        for (auto [dx, dy] : dirs) {
            int nx = bx + dx, ny = by + dy;
            if (nx < N && ny < M && A[nx][ny] >= A[ax][ay]) {
                if (!dfs(ax, ay, nx, ny, !turn)) {
                    opponent_loses = false;
                    break;
                }
            }
        }
        return dp[key] = opponent_loses;
    }
}

int solve(int n, int m, int q, vector<vector<int>> grid, vector<vector<int>> queries) {
    N = n; M = m; A = grid;
    int result = 0;
    dp.clear(); // Clear memoization cache for new game

    for (int i = 0; i < q; i++) {
        int x1 = queries[i][0] - 1; // Adjust to 0-based indexing
        int y1 = queries[i][1] - 1;
        int x2 = queries[i][2] - 1;
        int y2 = queries[i][3] - 1;
        
        // If Alice can win from this position, set bit i
        if (dfs(x1, y1, x2, y2, true)) {
            result |= (1 << i);
        }
    }
    
    return result;
}

int main() {
    // Read input
    int N, M, Q;
    cin >> N >> M >> Q;
    
    // Read grid A
    vector<vector<int>> A(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }
    
    // Read queries
    vector<vector<int>> queries(Q, vector<int>(4));
    for (int i = 0; i < Q; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> queries[i][j];
        }
    }
    
    // Compute and output result
    int result = solve(N, M, Q, A, queries);
    cout << result << endl;
    
    return 0;
}