#include <bits/stdc++.h>
using namespace std;

const int LOG = 30;

void buildBinaryLiftingTable(vector<vector<int>>& up, int n) {
    for (int j = 1; j < LOG; j++) {
        for (int i = 0; i < n; i++) {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<vector<int>> up(n, vector<int>(LOG));
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        up[i][0] = v - 1; // 0-index
    }

    buildBinaryLiftingTable(up, n);

    while (q--) {
        int node;
        long long k;
        cin >> node >> k;
        node--;
        for (int j = 0; j < LOG; j++) {
            if (k & (1LL << j)) {
                node = up[node][j];
            }
        }
        cout << node + 1 << '\n'; // ✅ use '\n' instead of endl
    }

    return 0;
}
