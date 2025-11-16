#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstring>

using namespace std;
const int INF = 1000000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    for (int tc = 1; tc <= T; ++tc) {
        int H, D;
        cin >> H >> D;
        // read 5 fuels: each line has minutes seconds heating
        vector<int> timePerKm(5);
        vector<int> heatPerKm(5);
        for (int i = 0; i < 5; ++i) {
            int tmin, tsec, h;
            cin >> tmin >> tsec >> h;
            timePerKm[i] = tmin * 60 + tsec;
            heatPerKm[i] = h;
        }

        // dp[d][h] = min time in seconds to cover d kms with heat h
        // we only need up to D and H
        vector< vector<int> > dp(D+1, vector<int>(H+1, INF));
        dp[0][0] = 0;

        for (int d = 0; d < D; ++d) {
            for (int h = 0; h <= H; ++h) {
                if (dp[d][h] == INF) continue;
                int cur = dp[d][h];
                // try each fuel for next km
                for (int f = 0; f < 5; ++f) {
                    int nh = h + heatPerKm[f];
                    if (nh > H) continue;
                    int nt = cur + timePerKm[f];
                    if (nt < dp[d+1][nh]) dp[d+1][nh] = nt;
                }
            }
        }

        int best = INF;
        for (int h = 0; h <= H; ++h) {
            best = min(best, dp[D][h]);
        }

        cout << "Case #" << tc << "\n";
        if (best == INF) {
            cout << -1 << "\n";
        } else {
            int minutes = best / 60;
            int seconds = best % 60;
            cout << minutes << " " << seconds << "\n";
        }
    }

    return 0;
}
