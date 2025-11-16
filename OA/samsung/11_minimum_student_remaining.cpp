#include<bits/stdc++.h>
using namespace std;

int findMinStudent(vector<int>& students, int k) {
    int n = students.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int len = 1; len <= n; len++) {
        for (int l = 0; l <= n - len; l++) {
            int r = l + len - 1;
            if (len == 1) {
                dp[l][r] = 1;
                continue;
            }
            if (len == 2) {
                dp[l][r] = 2;
                continue;
            }
            dp[l][r] = len;
            // splits
            for (int m = l; m < r; m++) {
                dp[l][r] = min(dp[l][r], dp[l][m] + dp[m + 1][r]);
            }
            // triplets
            for (int q = l; q <= r; q++) {
                // left p
                int min_left = INT_MAX;
                for (int p = l; p < q; p++) {
                    if (students[p] + k == students[q]) {
                        bool can_remove_inner = (p + 1 > q - 1) || (dp[p + 1][q - 1] == 0);
                        if (can_remove_inner) {
                            int left_rem = (p - 1 >= l) ? dp[l][p - 1] : 0;
                            min_left = min(min_left, left_rem);
                        }
                    }
                }
                // right s
                int min_right = INT_MAX;
                for (int s = q + 1; s <= r; s++) {
                    if (students[q] + k == students[s]) {
                        bool can_remove_inner = (q + 1 > s - 1) || (dp[q + 1][s - 1] == 0);
                        if (can_remove_inner) {
                            int right_rem = (s + 1 <= r) ? dp[s + 1][r] : 0;
                            min_right = min(min_right, right_rem);
                        }
                    }
                }
                if (min_left != INT_MAX && min_right != INT_MAX) {
                    dp[l][r] = min(dp[l][r], min_left + min_right);
                }
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    int t;
    cin >> t;
    for (int test = 0; test < t; test++) {
        int n, k;
        cin >> n >> k;
        vector<int> students(n);
        for (int i = 0; i < n; i++) {
            cin >> students[i];
        }
        cout << findMinStudent(students, k) << endl;
    }
    return 0;
}