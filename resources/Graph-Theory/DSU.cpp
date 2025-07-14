class DSU {
public:
    vector<int> parent, rank;
    int components;  // Track number of connected components

    DSU(int n) {
        parent.resize(n ); ///NOT HERE: n+1 for 1-based indexing
        rank.resize(n , 0);
        iota(parent.begin(), parent.end(), 0);
        components = n; //change to n-1 if 1-based indexing
    }

    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]);  // Path compression
        return parent[x];
    }

    bool unite(int x, int y) {
        int xr = find(x);
        int yr = find(y);
        if (xr == yr) return false;  // Already in the same component

        if (rank[xr] < rank[yr]) {
            parent[xr] = yr;
        } else if (rank[yr] < rank[xr]) {
            parent[yr] = xr;
        } else {
            parent[yr] = xr;
            rank[xr]++;
        }
        components--;  // track fully connected or not , dsu.components==1 means fully connected;
        return true;
    }
};
