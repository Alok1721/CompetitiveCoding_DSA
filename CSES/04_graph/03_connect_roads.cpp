#include <bits/stdc++.h>
const int mod =1e9+7;
using namespace std;
typedef long long ll;


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

int main()
{
    int t=1;
    // cin>> t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        DSU dsu(n);
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            dsu.unite(u-1,v-1);
        }

        vector<int>reps;
        for(int i=0;i<n;i++)
        {
            if(dsu.find(i)==i)
            {
                reps.push_back(i);
            }
        }
        cout<<reps.size()-1<<endl;
        for(int i=1;i<reps.size();i++)
        {
            cout<<reps[i-1]+1<<" "<<reps[i]+1<<endl;
        }
       
    }
    return 0;
}