class BipartiteChecker {
public:
    vector<vector<int>> adj;
    vector<int> color;
    int n;

    BipartiteChecker(int size) {
        n = size;
        adj.resize(n + 1);  // 1-based indexing
        color.assign(n + 1, 0);  // 0: unvisited, 1 or 2: colored
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);  // Undirected graph
    }

    bool isBipartiteUtil(int start) {
        queue<int> q;
        q.push(start);
        color[start] = 1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (color[v] == 0) {
                    color[v] = 3 - color[u]; // Alternate color
                    q.push(v);
                } else if (color[v] == color[u]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite() {
        for (int i = 1; i <= n; ++i) {
            if (color[i] == 0) {
                if (!isBipartiteUtil(i))
                    return false;
            }
        }
        return true;
    }

    vector<int> getColors() {
        return color;
    }
};
