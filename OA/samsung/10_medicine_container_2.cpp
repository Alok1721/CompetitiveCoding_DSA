#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    const int INF = 1e9 + 5;
    for(int cas = 0; cas < t; cas++) {
        int target, m;
        cin >> target >> m;
        vector<int> capacities(m);
        for(int i = 0; i < m; i++) {
            cin >> capacities[i];
        }
        vector<int> dp(target + 1, INF);
        dp[0] = 0;
        set<int> coin_set;
        for(int c : capacities) {
            if(c <= target) {
                coin_set.insert(c);
            }
        }
        for(size_t i = 0; i < capacities.size(); ++i) {
            for(size_t j = i + 1; j < capacities.size(); ++j) {
                long long sum = (long long)capacities[i] + capacities[j];
                if(sum <= target) {
                    coin_set.insert(sum);
                }
            }
        }
        vector<int> coins(coin_set.begin(), coin_set.end());
        for(int c : coins) {
            for(int j = c; j <= target; ++j) {
                if(dp[j - c] != INF) {
                    dp[j] = min(dp[j], dp[j - c] + 1);
                }
            }
        }
        int ans = dp[target];
        if(ans == INF) {
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}