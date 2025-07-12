#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int Tom_Jerry(int N, vector<int> Tom, vector<int> Jerry) {
    int L = 2 * N;
    vector<vector<int>> G(N + 1);

    // Group Jerry[i]s by their Tom[i] values
    for (int i = 0; i < N; i++) {
        G[Tom[i]].push_back(Jerry[i]);
    }

    int B = floor(sqrt(2.0 * N));
    vector<int> small, large;

    for (int v = 1; v <= N; v++) {
        if (!G[v].empty()) {
            if (v <= B) small.push_back(v);
            else large.push_back(v);
        }
    }

    // compress values for small tom values
    vector<vector<pair<int, int>>> comp(B + 1); // comp[tom] = vector of (jerry, count)
    for (int v : small) {
        auto& g = G[v];
        sort(g.begin(), g.end());
        auto& c = comp[v];

        for (int x : g) {
            if (c.empty() || c.back().first != x)
                c.emplace_back(x, 1);
            else
                c.back().second++;
        }
    }

    long long ans = 0;
    int M = small.size();

    // Pairs of (v, v) where P = v*v
    for (int i = 0; i < M; i++) {
        int v = small[i];
        auto& cv = comp[v];
        long long P = 1LL * v * v;

        if (P <= L) {
            int l = 0, r = (int)cv.size() - 1;
            while (l <= r) {
                long long s = cv[l].first + cv[r].first;
                if (s < P) l++;
                else if (s > P) r--;
                else {
                    if (l == r)
                        ans += 1LL * cv[l].second * (cv[l].second - 1) / 2;
                    else
                        ans += 1LL * cv[l].second * cv[r].second;
                    l++; r--;
                }
            }
        }

        // Pairs of (v, u) where v < u
        for (int j = i + 1; j < M; j++) {
            int u = small[j];
            long long P2 = 1LL * v * u;
            if (P2 > L) break;

            auto& cu = comp[u];
            int l = 0, r = (int)cu.size() - 1;

            while (l < cv.size() && r >= 0) {
                long long s = cv[l].first + cu[r].first;
                if (s < P2) l++;
                else if (s > P2) r--;
                else {
                    ans += 1LL * cv[l].second * cu[r].second;
                    l++; r--;
                }
            }
        }
    }

    // Pairs of large v with small u
    for (int v : large) {
        auto& gv = G[v];
        for (int x : gv) {
            for (int u : small) {
                long long P = 1LL * v * u;
                if (P > L) break;

                int need = P - x;
                auto& cu = comp[u];

                int lo = 0, hi = cu.size();
                while (lo < hi) {
                    int m = (lo + hi) / 2;
                    if (cu[m].first < need) lo = m + 1;
                    else hi = m;
                }

                if (lo < cu.size() && cu[lo].first == need)
                    ans += cu[lo].second;
            }
        }
    }

    return (int)ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> tom(n), jerry(n);
    for (int i = 0; i < n; ++i) cin >> tom[i];
    for (int i = 0; i < n; ++i) cin >> jerry[i];

    int result = Tom_Jerry(n, tom, jerry);
    cout << result << endl;
    return 0;
}
