#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<int> qty(N), tx(N);
        for (int i = 0; i < N; i++) {
            cin >> qty[i] >> tx[i];
        }
        const int MAXF = 200010;
        auto enc = [&](int a0, int a1, int a2) -> long long {
            return (long long)a0 * MAXF * MAXF + (long long)a1 * MAXF + a2;
        };
        unordered_map<long long, long long> prevv;
        prevv[enc(0, 0, 0)] = 0;
        for (int i = 0; i < N; i++) {
            unordered_map<long long, long long> nextt;
            for (auto& p : prevv) {
                long long key = p.first;
                long long cost = p.second;
                int a2 = key % MAXF;
                key /= MAXF;
                int a1 = key % MAXF;
                key /= MAXF;
                int a0 = key;
                // opt 1: pay
                {
                    int na0 = a0;
                    int na1 = a1;
                    int na2 = a2;
                    long long nc = cost + tx[i];
                    long long nkey = enc(na0, na1, na2);
                    auto it = nextt.find(nkey);
                    if (it == nextt.end()) {
                        nextt[nkey] = nc;
                    } else {
                        it->second = min(it->second, nc);
                    }
                }
                // opt 2: buy
                {
                    int na0 = a0 + qty[i];
                    int na1 = a1;
                    int na2 = a2;
                    long long nc = cost + 2LL * tx[i];
                    long long nkey = enc(na0, na1, na2);
                    auto it = nextt.find(nkey);
                    if (it == nextt.end()) {
                        nextt[nkey] = nc;
                    } else {
                        it->second = min(it->second, nc);
                    }
                }
                // opt 3: trade
                {
                    int totalv = a0 + a1 + a2;
                    if (totalv >= qty[i]) {
                        int qq = qty[i];
                        int need = qq;
                        int rem_from_a2 = min(a2, need);
                        need = max(0, qq - a2);
                        int rem_from_a1 = min(a1, need);
                        need = max(0, need - a1);
                        int rem_from_a0 = need;
                        int rem0 = a0 - rem_from_a0;
                        int rem1 = a1 - rem_from_a1;
                        int na0 = 0;
                        int na1 = rem0;
                        int na2 = rem1;
                        long long nc = cost;
                        long long nkey = enc(na0, na1, na2);
                        auto it = nextt.find(nkey);
                        if (it == nextt.end()) {
                            nextt[nkey] = nc;
                        } else {
                            it->second = min(it->second, nc);
                        }
                    }
                }
            }
            prevv = std::move(nextt);
        }
        long long ans = LLONG_MAX;
        for (auto& p : prevv) {
            ans = min(ans, p.second);
        }
        cout << "Case #" << t << ":" << endl;
        cout << ans << endl;
    }
    return 0;
}