#include <iostream>
#include <vector>
using namespace std;

void solve(int N, vector<int>& A) {
    vector<int> result(N, 0);
    vector<long long> prefixSum(N, 0);

    // Start from the last index
    for (int i = N - 1; i >= 0; --i) {
        if (A[i] > 0) {
            result[i] = 1;
        } else if (i + 1 < N && result[i + 1] > 0 && A[i] + prefixSum[i + 1] > 0) {
            result[i] = 1 + result[i + 1];
        } else {
            result[i] = 0;
        }

        // Store prefix sum from this index forward (only if valid)
        if (result[i] > 0) {
            prefixSum[i] = A[i];
            if (i + 1 < N && result[i + 1] > 0) {
                prefixSum[i] += prefixSum[i + 1];
            }
        }
    }

    // Print result
    for (int i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
}

// Main function for custom input
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    solve(N, A);
    return 0;
}
