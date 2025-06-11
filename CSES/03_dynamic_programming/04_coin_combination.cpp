#include <bits/stdc++.h>
#define mod ((int)1e9 + 7)
using namespace std;

// Make dp global if x is large
long long dp[1000001][101];  // max x = 1e6, max n = 100

long long findCombination(long long x, vector<long long>& coin, int j)
{
    if (x == 0) return 1;
    if (x < 0 || j >= (int)coin.size()) return 0;

    if (dp[x][j] != -1) return dp[x][j];

    long long ans = 0;
    if (x >= coin[j]) {
        ans = (ans + findCombination(x - coin[j], coin, j)) % mod;
    }
    ans = (ans + findCombination(x, coin, j + 1)) % mod;

    return dp[x][j] = ans;
}

int main()
{
    int n;
    long long x;
    cin >> n >> x;

    // Manual initialization since memset doesn't work for long long
    for (int i = 0; i <= x; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = -1;

    vector<long long> coin(n);
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }

    cout << findCombination(x, coin, 0) << endl;
    return 0;
}
