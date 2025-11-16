#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    for (int t = 0; t < T; t++) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> grid(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < M; j++) {
                grid[i][j] = s[j] - '0';
            }
        }
        vector<vector<int>> cc_id(N, vector<int>(M, -1));
        int cc_cnt = 0;
        vector<int> phone_of_cc;
        vector<int> size_of_cc;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] != 0 && cc_id[i][j] == -1) {
                    int cur_phone = grid[i][j];
                    int sz = 0;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    cc_id[i][j] = cc_cnt;
                    sz++;
                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        for (int d = 0; d < 4; d++) {
                            int nx = x + dx[d];
                            int ny = y + dy[d];
                            if (nx >= 0 && nx < N && ny >= 0 && ny < M && grid[nx][ny] == cur_phone && cc_id[nx][ny] == -1) {
                                cc_id[nx][ny] = cc_cnt;
                                sz++;
                                q.push({nx, ny});
                            }
                        }
                    }
                    phone_of_cc.push_back(cur_phone);
                    size_of_cc.push_back(sz);
                    cc_cnt++;
                }
            }
        }
        vector<vector<bool>> vis(N, vector<bool>(M, false));
        vector<vector<vector<int>>> merge_groups(6);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == 0 && !vis[i][j]) {
                    vector<pair<int, int>> zero_cells;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vis[i][j] = true;
                    zero_cells.push_back({i, j});
                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        for (int d = 0; d < 4; d++) {
                            int nx = x + dx[d];
                            int ny = y + dy[d];
                            if (nx >= 0 && nx < N && ny >= 0 && ny < M && grid[nx][ny] == 0 && !vis[nx][ny]) {
                                vis[nx][ny] = true;
                                q.push({nx, ny});
                                zero_cells.push_back({nx, ny});
                            }
                        }
                    }
                    set<int> border_set;
                    for (auto [x, y] : zero_cells) {
                        for (int d = 0; d < 4; d++) {
                            int nx = x + dx[d];
                            int ny = y + dy[d];
                            if (nx >= 0 && nx < N && ny >= 0 && ny < M && grid[nx][ny] != 0) {
                                border_set.insert(cc_id[nx][ny]);
                            }
                        }
                    }
                    vector<int> border(border_set.begin(), border_set.end());
                    if (border.empty()) continue;
                    vector<vector<int>> border_regions(6);
                    for (int c : border) {
                        int p = phone_of_cc[c];
                        border_regions[p].push_back(c);
                    }
                    int best_ms = -1;
                    int best_p = -1;
                    for (int p = 1; p <= 5; p++) {
                        if (border_regions[p].empty()) continue;
                        int ms = 0;
                        for (int c : border_regions[p]) {
                            ms = max(ms, size_of_cc[c]);
                        }
                        if (ms > best_ms || (ms == best_ms && p > best_p)) {
                            best_ms = ms;
                            best_p = p;
                        }
                    }
                    if (best_p == -1) continue;
                    const vector<int>& sel = border_regions[best_p];
                    merge_groups[best_p].push_back(sel);
                }
            }
        }
        int total = 0;
        for (int p = 1; p <= 5; p++) {
            vector<int> my_ccs;
            for (int k = 0; k < cc_cnt; k++) {
                if (phone_of_cc[k] == p) my_ccs.push_back(k);
            }
            int num = my_ccs.size();
            if (num == 0) continue;
            vector<int> par(cc_cnt, -1);
            for (int cc : my_ccs) par[cc] = cc;
            std::function<int(int)> find = [&](int x) -> int {
                if (par[x] != x) par[x] = find(par[x]);
                return par[x];
            };
            for (const auto& group : merge_groups[p]) {
                if (group.size() < 2) continue;
                int root = find(group[0]);
                for (size_t i = 1; i < group.size(); i++) {
                    int r = find(group[i]);
                    if (r != root) {
                        par[r] = root;
                    }
                }
            }
            unordered_set<int> roots;
            for (int cc : my_ccs) {
                roots.insert(find(cc));
            }
            total += roots.size();
        }
        cout << total << endl;
    }
    return 0;
}