#include <bits/stdc++.h>
using namespace std;

int dfs(unordered_map<int, vector<int>>& graph, int node) {
    vector<int>times;//time needed to inform the children node
    for(auto nei:graph[node])
    {
        times.push_back(dfs(graph,nei));
    }
    int maxTime=0;
    for(int i=0;i<times.size();i++)
    {
        maxTime=max(maxTime,times[i]+i+1);
    }
    return maxTime;
}

int finMinTime(vector<vector<int>> edges, int n) {
    unordered_map<int, vector<int>> graph;
    for (auto it : edges) {
        graph[it[0]].push_back(it[1]);
    }
    return dfs(graph, 1); // assuming root = 1
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> edges;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    cout << finMinTime(edges, n);
    return 0;
}
