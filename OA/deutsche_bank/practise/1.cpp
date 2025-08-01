#include <iostream>
#include <vector>
using namespace std;

int countMaxDifferencePairs(int N, vector<int>& arr, int K) {
    int count = 0;
    int j = 0;

    for (int i = 0; i < N; ++i) {
        // Ensure j > i
        if (j <= i) j = i + 1;

        // Move j forward until arr[j] - arr[i] >= K
        while (j < N && arr[j] - arr[i] < K) {
            ++j;
        }

        // Add all valid (i, j) pairs
        count += N - j;
    }

    return count;
}

int main() {
    int N, K;
    cin >> N;
    vector<int> arr(N);

    for (int i = 0; i < N; ++i) cin >> arr[i];
    cin >> K;

    cout << countMaxDifferencePairs(N, arr, K) << endl;
    return 0;
}
