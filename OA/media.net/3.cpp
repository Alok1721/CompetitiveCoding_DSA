#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define pii pair<int, int>
#define ll long long

class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int xr = find(x);
        int yr = find(y);
        if (xr == yr) return;

        if (rank[xr] < rank[yr])
            parent[xr] = yr;
        else if (rank[xr] > rank[yr])
            parent[yr] = xr;
        else {
            parent[yr] = xr;
            rank[xr]++;
        }
    }

    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
};

int solve(vector<vector<int>>& A) {
    int n = A.size();
    int total = n * n;
    DSU dsu(total);

    // Step 1: Unite reachable cells
    auto getIndex = [&](int i, int j) {
        return i * n + j;
    };

    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] == -1) continue;
            for (int d = 0; d < 4; d++) {
                int ni = i + dx[d], nj = j + dy[d];
                if (ni >= 0 && nj >= 0 && ni < n && nj < n && A[ni][nj] != -1) {
                    dsu.unite(getIndex(i, j), getIndex(ni, nj));
                }
            }
        }
    }

    // Step 2: Preprocess positions by value
    unordered_map<int, vector<pii>> val_to_cells;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (A[i][j] != -1)
                val_to_cells[A[i][j]].emplace_back(i, j);

    // Step 3: Main loop
    ll result = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int curr = A[i][j];
            if (curr == -1) {
                result = (result + MOD - 1) % MOD;  // +(-1)
                continue;
            }

            int root1 = dsu.find(getIndex(i, j));
            ll sed = 0;

            // Check for all multiples of current cell value
            for (auto& [val, cells] : val_to_cells) {
                if (val % curr != 0) continue;

                for (auto& [x, y] : cells) {
                    int root2 = dsu.find(getIndex(x, y));
                    if (root1 != root2) {
                        sed = (sed + val) % MOD;
                    }
                }
            }

            result = (result + sed) % MOD;
        }
    }

    return (int)result;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> A(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> A[i][j];

    cout << solve(A) << endl;
    return 0;
}
