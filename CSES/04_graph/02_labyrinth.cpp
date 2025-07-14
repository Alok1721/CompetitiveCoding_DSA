#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int mod = 1e9 + 7;

vector<pii> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
string dirChar = "DRUL";

string isPath(vector<vector<char>>& graph, pii& start, pii& end, string& result) {
    int m = graph.size();
    int n = graph[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    vector<vector<pii>> parent(m, vector<pii>(n, {-1, -1}));

    queue<pii> q;
    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();

        if (i == end.first && j == end.second) {
            string path;
            pii curr = end;
            while (curr != start) {
                pii par = parent[curr.first][curr.second];
                int dx = curr.first - par.first;
                int dy = curr.second - par.second;
                for (int d = 0; d < 4; ++d) {
                    if (dirs[d] == make_pair(dx, dy)) {
                        path += dirChar[d];
                        break;
                    }
                }
                curr = par;
            }
            reverse(path.begin(), path.end());
            result = path;
            return "YES";
        }

        for (int d = 0; d < 4; d++) {
            int nx = i + dirs[d].first;
            int ny = j + dirs[d].second;
            if (nx >= 0 && ny >= 0 && nx < m && ny < n &&
                !visited[nx][ny] && graph[nx][ny] != '#') {
                visited[nx][ny] = true;
                parent[nx][ny] = {i, j};
                q.push({nx, ny});
            }
        }
    }
    return "NO";
}

int main() {
    int t = 1;
    while (t--) {
        int m, n;
        cin >> m >> n;
        vector<vector<char>> graph(m, vector<char>(n));
        pair<int, int> start, end;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> graph[i][j];
                if (graph[i][j] == 'A') {
                    start = {i, j};
                }
                if (graph[i][j] == 'B') {
                    end = {i, j};
                }
            }
        }

        string result;
        string status = isPath(graph, start, end, result);
        cout << status << '\n';
        if (status == "YES") {
            cout << result.size() << '\n';
            cout << result << '\n';
        }
    }
    return 0;
}
