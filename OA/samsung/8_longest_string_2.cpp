#include <bits/stdc++.h>
using namespace std;

int solve(const vector<int>& a) {
    vector<vector<int>> dp(10, vector<int>(10, INT_MIN));

    for (const auto& v : a) {
        string s = to_string(v);
        int len = (int)s.length();
        int first = s.front() - '0';
        int last = s.back() - '0';

        // Try to extend existing chains
        for (int i = 0; i < 10; i++) {
            if (dp[i][first] != INT_MIN) {
                dp[i][last] = max(dp[i][last], dp[i][first] + len);
            }
        }

        // Start a new chain
        dp[first][last] = max(dp[first][last], len);
    }

    int ans = 0;
    for (int i = 0; i < 10; i++) {
        ans = max(ans, dp[i][i]);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << solve(a) << endl;
    return 0;
}
