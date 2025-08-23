bool dfs(int node, vector<int> adj[], vector<bool>& visited, vector<bool>& recStack) {
    visited[node] = true;
    recStack[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, adj, visited, recStack)) return true;
        } else if (recStack[neighbor]) {
            return true; // back edge found -> cycle
        }
    }

    recStack[node] = false; // remove from recursion stack
    return false;
}

bool hasCycleDirected(int n, vector<int> adj[]) {
    vector<bool> visited(n, false), recStack(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dfs(i, adj, visited, recStack)) return true;
    }
    return false;
}
