#include <bits/stdc++.h>
using namespace std;
typedef long long llint;

llint findMoves(int n, llint a[], llint b[]) {
    int k = (n - 1) / 2; // Number of steps on each side of water level
    llint min_changes = LLONG_MAX;
    
    // Collect possible water level heights
    vector<llint> candidates;
    for (int i = 0; i < n; i++) {
        llint offset = (i < k) ? (k - i) : (i == k) ? 0 : (i - k);
        candidates.push_back(a[i] - offset); // Possible w from a[i]
        candidates.push_back(b[i] - offset); // Possible w from b[i]
    }
    
    // Try each candidate water level
    for (llint w : candidates) {
        llint changes = 0;
        for (int i = 0; i < n; i++) {
            llint target;
            if (i < k) {
                target = w + (k - i); // Descending part
            } else if (i == k) {
                target = w; // Water level
            } else {
                target = w + (i - k); // Ascending part
            }
            changes += abs(a[i] - target) + abs(b[i] - target);
        }
        min_changes = min(min_changes, changes);
    }
    
    return min_changes;
}

int main() {
    int n;
    cin >> n;
    llint a[10001], b[10001];
    
    // Read East-West steps
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Read North-South steps
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    cout << findMoves(n, a, b) << endl;
    return 0;
}