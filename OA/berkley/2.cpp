#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, sz;
    DSU(int n) {
        parent.resize(n);
        sz.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (sz[a] < sz[b]) swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> strength(n);
    for (int i = 0; i < n; i++) cin >> strength[i];

    int numCards, pairCount;
    cin >> numCards >> pairCount; // pairCount is always 2

    DSU dsu(n);

    for (int i = 0; i < numCards; i++) {
        int a, b;
        cin >> a >> b;
        dsu.unite(a - 1, b - 1); // convert to 0-based indexing
    }

    // Sum strengths for each root
    vector<long long> teamPower(n, 0);
    for (int i = 0; i < n; i++) {
        int root = dsu.find(i);
        teamPower[root] += strength[i];
    }

    // Find max team power
    long long maxPower = 0;
    for (long long p : teamPower) {
        maxPower = max(maxPower, p);
    }

    cout << maxPower << "\n";
    return 0;
}
