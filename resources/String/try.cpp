#include <bits/stdc++.h>
using namespace std;

int maxWeight(vector<int>& weights, int w1, int w2) {
    int n = weights.size();
    
    // 2D DP table (rolling array is enough since we go backwards)
    vector<vector<int>> dp(w1 + 1, vector<int>(w2 + 1, 0));

    for (int w : weights) {
        // go backwards to avoid reusing the same item
        for (int c1 = w1; c1 >= 0; c1--) {
            for (int c2 = w2; c2 >= 0; c2--) {
                if (c1 >= w) {
                    dp[c1][c2] = max(dp[c1][c2], dp[c1 - w][c2] + w);
                }
                if (c2 >= w) {
                    dp[c1][c2] = max(dp[c1][c2], dp[c1][c2 - w] + w);
                }
            }
        }
    }

    return dp[w1][w2];
}

int main() {
    vector<int> weights = {10, 8, 3, 8};
    int w1 = 5, w2 = 17;

    cout << maxWeight(weights, w1, w2) << endl; // Output: 19
    return 0;
}
