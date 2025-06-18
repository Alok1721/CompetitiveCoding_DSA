#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> ops;
        
        // For each row i, rotate left by (i-1) positions
        for (int i = 2; i <= n; ++i) {
            int k = i - 1; // Shift amount
            if (k > 0) {
                // Three reversals to achieve left rotation by k
                ops.push_back({i, 1, k});
                ops.push_back({i, k + 1, n});
                ops.push_back({i, 1, n});
            }
        }
        
        // Output operations
        cout << ops.size() << '\n';
        for (const auto& op : ops) {
            cout << op[0] << ' ' << op[1] << ' ' << op[2] << '\n';
        }
    }
    
    return 0;
}