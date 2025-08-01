#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll countMultiples(ll x, const vector<int>& A) {
    ll count = 0;
    for (int a : A) {
        count += x / a;
    }
    return count;
}

int main() {
    int N;
    ll K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    ll low = 1, high = 1e18, ans = -1;
    while (low < high) {
        ll mid = low + (high - low) / 2;
        if (countMultiples(mid, A) >= K) {
            high = mid; // potential answer
        } else {
            low = mid + 1;
        }
    }

    cout << low << endl;
    return 0;
}
