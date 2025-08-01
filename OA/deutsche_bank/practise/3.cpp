#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

class TreeDivision {
private:
    vector<vector<int>> graph;
    vector<int> towns;
    vector<long long> subtreeSum;
    long long totalTowns;
    int minDiff;
    int N;
    
public:
    TreeDivision(int n) : N(n) {
        graph.resize(n);
        subtreeSum.resize(n);
        totalTowns = 0;
        minDiff = INT_MAX;
    }
    
    long long dfs(int node, int parent) {
        subtreeSum[node] = towns[node];
        
        // Calculate subtree sum including all children
        for (int neighbor : graph[node]) {
            if (neighbor != parent) {
                subtreeSum[node] += dfs(neighbor, node);
            }
        }
        
        // If this is not the root, calculate difference when cutting edge to parent
        if (parent != -1) {
            long long part1 = subtreeSum[node];           // Subtree rooted at current node
            long long part2 = totalTowns - part1;        // Remaining part
            minDiff = min(minDiff, (int)abs(part1 - part2));
        }
        
        return subtreeSum[node];
    }
    
    int solve(vector<int>& townsInput, vector<vector<int>>& roads) {
        towns = townsInput;
        
        // Build adjacency list (convert to 0-indexed)
        for (auto& edge : roads) {
            int u = edge[0] - 1;  // Convert to 0-indexed
            int v = edge[1] - 1;  // Convert to 0-indexed
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        // Calculate total towns
        totalTowns = 0;
        for (int town : towns) {
            totalTowns += town;
        }
        
        // Start DFS from node 0
        dfs(0, -1);
        
        return minDiff;
    }
};

int TownDifference(int N, vector<int>& towns, vector<vector<int>>& roads) {
    TreeDivision td(N);
    return td.solve(towns, roads);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<int> towns(N);
    for (int i = 0; i < N; i++) {
        cin >> towns[i];
    }
    
    vector<vector<int>> roads(N - 1, vector<int>(2));
    for (int i = 0; i < N - 1; i++) {
        cin >> roads[i][0] >> roads[i][1];
    }
    
    cout << TownDifference(N, towns, roads) << endl;
    
    return 0;
}
