#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int countValidStrings(int N) {
    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(3, vector<int>(3, 0)));
    for (int i = 0; i < 3; ++i) {    
        for (int j = 0; j < 3; ++j) { 
            dp[2][i][j] = 1;
        }
    }

    for (int len = 2; len < N; ++len) {
        for (int x = 0; x < 3; ++x) {
            for (int y = 0; y < 3; ++y) {
                int val = dp[len][x][y];
                for (int z = 0; z < 3; ++z) { 
                    if (x == 0 && y == 1 && z == 2) continue; 
                    dp[len + 1][y][z] = (dp[len + 1][y][z] + val) % MOD;
                }
            }
        }
    }

    int total = 0;
    if (N == 1) return 3; 
    if (N == 2) return 9; 

    for (int x = 0; x < 3; ++x)
        for (int y = 0; y < 3; ++y)
            total = (total + dp[N][x][y]) % MOD;

    return total;
}

int main() {
    int N;
    cin >> N;
    cout << countValidStrings(N) << endl;
    return 0;
}
