#include <bits/stdc++.h>
using namespace std;

// Disjoint Set (Union-Find) with Path Compression + Union by Rank
class DSU {
public:
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    
    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }
    
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if(px == py) return;
        if(rank[px] < rank[py]) parent[px] = py;
        else if(rank[px] > rank[py]) parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
    }
};

class Solution {
public:
    int kruskalMST(int V, vector<tuple<int,int,int>>& edges) {
        // Sort edges by weight
        sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
            return get<2>(a) < get<2>(b);
        });
        
        DSU dsu(V);
        int mstWeight = 0;
        
        for(auto &[u,v,w] : edges) {
            if(dsu.find(u) != dsu.find(v)) {
                mstWeight += w;
                dsu.unite(u,v);
            }
        }
        return mstWeight;
    }
};

int main() {
    int V = 5;
    vector<tuple<int,int,int>> edges = {
        {0,1,2}, {0,3,6}, {1,2,3}, {1,3,8}, {1,4,5}, {2,4,7}, {3,4,9}
    };
    
    Solution obj;
    cout << "MST Weight: " << obj.kruskalMST(V, edges) << endl;
    return 0;
}
