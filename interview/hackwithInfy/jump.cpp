#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int findMinCost(vector<int>& A, int i, vector<int>& dp) {
    if (i == A.size() - 1) return 0; 
    if (dp[i] != -1) return dp[i];
    int cost = INF;
    if (i + 1 < A.size()) {
        cost = min(cost, 1 + findMinCost(A, i + 1, dp));
    }
    for (int j = i + 1; j < A.size(); ++j) {
        if (A[j] % A[i] == 0) {
            A[j] += 1; 
            cost = min(cost, A[i] + findMinCost(A, j, dp));
            A[j] -= 1; 
        }
    }
    return dp[i] = cost;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    vector<int> dp(N, -1);
    cout << findMinCost(A, 0, dp) << endl;

    return 0;
}
