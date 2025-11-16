#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

static const int NEG_INF = -1000000000;

struct Chat {
    int a, o, m;
    int price;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {

        // ---- Read input ----
        int A, O, M;
        int priceA, priceO;
        cin >> A >> O >> M;
        cin >> priceA >> priceO;

        int N;
        cin >> N;

        vector<Chat> chats(N);
        for (int i = 0; i < N; ++i) {
            cin >> chats[i].a >> chats[i].o >> chats[i].m >> chats[i].price;
        }

        long long bestAns = 0;

        // ---- Try all subsets of size 0..3 ----
        vector<int> idx(N);
        for (int i = 0; i < N; i++) idx[i] = i;

        // Enumerate all subsets
        for (int mask = 0; mask < (1 << N); ++mask) {
            int cnt = __builtin_popcount(mask);
            if (cnt > 3) continue;

            // collect chosen chat types
            vector<Chat> chosen;
            for (int i = 0; i < N; ++i)
                if (mask & (1 << i)) chosen.push_back(chats[i]);

            // ---- 3D DP: dp[a][o][m] = best revenue with exactly those fruits used ----
            static int dp[101][101][101];
            for (int i = 0; i <= A; ++i)
                for (int j = 0; j <= O; ++j)
                    for (int k = 0; k <= M; ++k)
                        dp[i][j][k] = NEG_INF;

            dp[0][0][0] = 0;

            // Unbounded knapsack: for each chat type
            for (auto &c : chosen) {
                for (int a = c.a; a <= A; ++a) {
                    for (int o = c.o; o <= O; ++o) {
                        for (int m = c.m; m <= M; ++m) {
                            if (dp[a - c.a][o - c.o][m - c.m] != NEG_INF) {
                                dp[a][o][m] = max(dp[a][o][m],
                                                  dp[a - c.a][o - c.o][m - c.m] + c.price);
                            }
                        }
                    }
                }
            }

            // ---- Compute best result with leftovers ----
            for (int a = 0; a <= A; ++a) {
                for (int o = 0; o <= O; ++o) {
                    for (int m = 0; m <= M; ++m) {
                        if (dp[a][o][m] == NEG_INF) continue;

                        long long leftoverA = A - a;
                        long long leftoverO = O - o;

                        long long revenue = dp[a][o][m]
                                            + leftoverA * priceA
                                            + leftoverO * priceO;

                        bestAns = max(bestAns, revenue);
                    }
                }
            }
        }

        // ---- Output ----
        cout << "Case #" << tc << "\n";
        cout << bestAns << "\n";
    }

    return 0;
}
