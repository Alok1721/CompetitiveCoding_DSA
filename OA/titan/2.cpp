#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5005;

long long a[MAXN];
long long f[MAXN][MAXN];
long long ans[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i][i] = ans[i][i] = a[i];
    }

    // Build f and ans for all ranges
    for (int len = 1; len < n; len++) {
        for (int l = 1; l + len <= n; l++) {
            int r = l + len;
            f[l][r] = f[l + 1][r] ^ f[l][r - 1];
            ans[l][r] = max({f[l][r], ans[l + 1][r], ans[l][r - 1]});
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << ans[l][r] << "\n";
    }

    return 0;
}
