#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int solve(int N, vector<pair<int, int>>& trees) {
    vector<int> u(N), v(N);
    for (int i = 0; i < N; i++) {
        u[i] = trees[i].first + trees[i].second;
        v[i] = trees[i].first - trees[i].second;
    }

    // Precompute prefix/suffix min/max for u and v
    vector<int> prefixMinU(N), prefixMaxU(N), suffixMinU(N), suffixMaxU(N);
    vector<int> prefixMinV(N), prefixMaxV(N), suffixMinV(N), suffixMaxV(N);

    prefixMinU[0] = prefixMaxU[0] = u[0];
    prefixMinV[0] = prefixMaxV[0] = v[0];
    for (int i = 1; i < N; i++) {
        prefixMinU[i] = min(prefixMinU[i - 1], u[i]);
        prefixMaxU[i] = max(prefixMaxU[i - 1], u[i]);
        prefixMinV[i] = min(prefixMinV[i - 1], v[i]);
        prefixMaxV[i] = max(prefixMaxV[i - 1], v[i]);
    }

    suffixMinU[N - 1] = suffixMaxU[N - 1] = u[N - 1];
    suffixMinV[N - 1] = suffixMaxV[N - 1] = v[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        suffixMinU[i] = min(suffixMinU[i + 1], u[i]);
        suffixMaxU[i] = max(suffixMaxU[i + 1], u[i]);
        suffixMinV[i] = min(suffixMinV[i + 1], v[i]);
        suffixMaxV[i] = max(suffixMaxV[i + 1], v[i]);
    }

    int result = INT_MAX;

    for (int i = 0; i < N; i++) {
        int minU = INT_MAX, maxU = INT_MIN;
        int minV = INT_MAX, maxV = INT_MIN;

        if (i > 0) {
            minU = min(minU, prefixMinU[i - 1]);
            maxU = max(maxU, prefixMaxU[i - 1]);
            minV = min(minV, prefixMinV[i - 1]);
            maxV = max(maxV, prefixMaxV[i - 1]);
        }

        if (i < N - 1) {
            minU = min(minU, suffixMinU[i + 1]);
            maxU = max(maxU, suffixMaxU[i + 1]);
            minV = min(minV, suffixMinV[i + 1]);
            maxV = max(maxV, suffixMaxV[i + 1]);
        }

        int maxDist = max(maxU - minU, maxV - minV);
        result = min(result, maxDist);
    }

    return result;
}

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> trees(N);
    for (int i = 0; i < N; i++) {
        cin >> trees[i].first >> trees[i].second;
    }
    cout << solve(N, trees) << endl;
    return 0;
}
