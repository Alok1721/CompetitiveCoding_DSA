#include <bits/stdc++.h>
using namespace std;

long long findMinSum(const vector<long long>& a) {
    int n = a.size();
    // Compute original prefix minimum sum and track contributions
    vector<long long> prefix_min(n);
    vector<int> last_min_idx(n);
    prefix_min[0] = a[0];
    last_min_idx[0] = 0;
    long long original_sum = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] <= prefix_min[i-1]) {
            prefix_min[i] = a[i];
            last_min_idx[i] = i;
        } else {
            prefix_min[i] = prefix_min[i-1];
            last_min_idx[i] = last_min_idx[i-1];
        }
        original_sum += prefix_min[i];
    }
    long long best = original_sum;

    // Try operations: for each j, find best i to minimize the sum
    for (int j = 1; j < n; ++j) {
        if (a[j] == 0) continue; // No benefit in setting a[j] = 0 if already 0
        // Try each i < j
        for (int i = 0; i < j; ++i) {
            long long new_sum = 0;
            long long min_so_far = (i == 0) ? a[0] + a[j] : a[0];
            new_sum += min_so_far;
            for (int k = 1; k < n; ++k) {
                if (k == i) {
                    min_so_far = min(min_so_far, a[i] + a[j]);
                } else if (k == j) {
                    min_so_far = min(min_so_far, 0LL);
                } else {
                    min_so_far = min(min_so_far, a[k]);
                }
                new_sum += min_so_far;
            }
            best = min(best, new_sum);
        }
    }

    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cout << findMinSum(a) << '\n';
    }

    return 0;
}