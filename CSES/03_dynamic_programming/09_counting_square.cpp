#include <bits/stdc++.h>
#define mod ((int)1e9+7)
using namespace std;

vector<int> dp(1e6+1);
void precompute() {
    dp[1] = 1; // Base case: 1 way to form a square of size 0
    dp[2]=8;
    for (int i = 3; i <= 1e6; i++) {
        dp[i] = (dp[i - 1]*3% mod + dp[i-2]*2%mod ) % mod; // Recurrence relation
    }
}


int main()
{
    precompute();
    int t;
    cin>> t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<dp[n]<<endl;
       
    }
    return 0;
}