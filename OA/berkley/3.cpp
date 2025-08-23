#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> state(n);
    for (int i = 0; i < n; i++) {
        cin >> state[i];
    }

    int m;
    cin >> m;

    vector<long long> dist(m);
    for (int i = 0; i < m; i++) {
        cin >> dist[i];
    }

    // If all ON
    if (all_of(state.begin(), state.end(), [](int x){ return x == 1; })) {
        cout << 0 << "\n";
        return 0;
    }

    // Find first ON
    int firstOn = -1;
    for (int i = 0; i < n; i++) {
        if (state[i] == 1) {
            firstOn = i;
            break;
        }
    }

    long long totalCable = 0;

    // Go right from firstOn
    for (int i = firstOn + 1; i < n; i++) {
        if (state[i] == 0) {
            totalCable += dist[i] - dist[i - 1];
            state[i] = 1; // Now ON
        }
    }

    // Go left from firstOn
    for (int i = firstOn - 1; i >= 0; i--) {
        if (state[i] == 0) {
            totalCable += dist[i + 1] - dist[i];
            state[i] = 1; // Now ON
        }
    }

    cout << totalCable << "\n";
    return 0;
}
