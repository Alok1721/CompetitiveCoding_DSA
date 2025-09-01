#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<char, vector<pair<char, double>>> graph; // adjacency list

    double dfs(char node, char end, unordered_set<char>& visited, double product) {
        if (node == end) return product;
        visited.insert(node);
        double maxProduct = -1; // default if no path found
        for (auto& [nei, w] : graph[node]) {
            if (visited.count(nei)) continue;
            double p = dfs(nei, end, visited, product * w);
            if (p != -1) maxProduct = max(maxProduct, p);
        }
        visited.erase(node);
        return maxProduct;
    }

    double maxProductPath(char start, char end) {
        if (!graph.count(start) || !graph.count(end)) return -1;
        unordered_set<char> visited;
        return dfs(start, end, visited, 1.0);
    }
};

int main() {
    Solution sol;
    // build graph
    sol.graph['A'].push_back({'B', 2});
    sol.graph['B'].push_back({'C', 3});
    sol.graph['A'].push_back({'C', 4});

    double ans = sol.maxProductPath('A', 'C'); // should explore paths A->C (4) and A->B->C (2*3=6)
    cout << ans << endl; // Output: 6
}
