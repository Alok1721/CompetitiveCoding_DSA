#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.assign(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return false;
        if (rank[px] < rank[py])
            parent[px] = py;
        else if (rank[px] > rank[py])
            parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
        return true;
    }
};

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    DSU dsu(N * M);
    vector<bool> hasDrop(N * M, false);
    int components = 0;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    while (Q--) {
        char type;
        cin >> type;
        if (type == 'd') {
            int x, y;
            cin >> x >> y;
            int id = (x - 1) * M + (y - 1);
            if (hasDrop[id]) continue; // already has drop
            hasDrop[id] = true;
            components++;

            // Check neighbors
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 1 && nx <= N && ny >= 1 && ny <= M) {
                    int nid = (nx - 1) * M + (ny - 1);
                    if (hasDrop[nid] && dsu.unite(id, nid)) {
                        components--; // merged two components
                    }
                }
            }
        }
        else if (type == 'c') {
            cout << components << "\n";
        }
    }
    return 0;
}
