#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int solve(const vector<int>& a) {
    vector dp(10, vector(10, INT_MIN));
    for (const auto& v : a) {
        const auto s = to_string(v);
        const int len = (int)s.length(), first = s.front() - '0', last = s.back() - '0';
        for (int i = 1; i < 10; i++) {
            dp[i][last] = max(dp[i][last], dp[i][first] + len);
        }
        dp[first][last] = max(dp[first][last], len);
    }
    int ans = 0;
    for (int i = 1; i < 10; i++)
        ans = max(ans, dp[i][i]);
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int maxLen = solve(arr);
    
    
    
    cout << maxLen << endl;
    
    return 0;
}