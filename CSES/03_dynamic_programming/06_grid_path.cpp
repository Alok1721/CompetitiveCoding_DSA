#include <bits/stdc++.h>
#define mod ((int)1e9+7)
using namespace std;



int main()
{
    int n;
    cin >> n;
    vector<string>grid(n);
    for(int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    vector<vector<int>> dp(n, vector<int>(n, 0));
    if(grid[0][0]=='*')
    {
        cout<<0<<endl;
        return 0;
    }

    dp[0][0] = 1; // Starting point
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == '*') {
                dp[i][j] = 0; // If there's a mine, no paths can go through
            } else {
                if(i > 0) dp[i][j] += dp[i-1][j]; // From above
                if(j > 0) dp[i][j] += dp[i][j-1]; // From left
                dp[i][j] %= mod; // To avoid overflow
            }
        }
    }
    cout << dp[n-1][n-1] << endl; // Output the number of paths to the bottom-right corner

    return 0;
}