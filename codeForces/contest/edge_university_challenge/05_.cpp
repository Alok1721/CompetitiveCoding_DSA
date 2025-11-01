#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

bool find_partition(const vector<long long>& a, vector<long long>& b) {
    int n = a.size();
    long long total = accumulate(a.begin(), a.end(), 0LL);
    
    long long left = 0;
    for (int i = 0; i < n - 1; ++i) {
        left += a[i];
        long long right = total - left;
        if (left == right) {
            // Valid partition
            for (int j = 0; j < n; ++j) {
                if (j <= i) b[j] = a[j];
                else b[j] = a[j];
            }
            return true;
        }
    }
    return false;
}

vector<vector<long long>> solve(vector<long long> a) {
    vector<vector<long long>> operations;
    int max_steps = 17;

    while (accumulate(a.begin(), a.end(), 0LL) > 0 && operations.size() < max_steps) {
        vector<long long> b(a.size(), 0);
        if (!find_partition(a, b)) {
            return {};  // No valid partition found
        }
        operations.push_back(b);
        for (int i = 0; i < a.size(); ++i) {
            a[i] -= b[i];
        }
    }

    if (accumulate(a.begin(), a.end(), 0LL) == 0) return operations;
    return {};
}

int main() {
    ios_base::sync_with_stdio(false);
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

        vector<vector<long long>> result = solve(a);

        if (result.empty()) {
            cout << -1 << '\n';
        } else {
            cout << result.size() << '\n';
            for (const auto& op : result) {
                for (auto x : op) cout << x << " ";
                cout << '\n';
            }
        }
    }

    return 0;
}
