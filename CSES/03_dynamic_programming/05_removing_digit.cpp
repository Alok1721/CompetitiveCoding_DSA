#include <bits/stdc++.h>
#define mod ((int)1e9+7)
using namespace std;



int main()
{
    int n;
    cin>>n;
    vector<int>dp(n+1,1e9);

    dp[0] = 0; // Base case: 0 digits removed requires 0 operations
    for(int i=1;i<=n;i++)
    {
        string a=to_string(i);
        for(auto c:a)
        {
            int digit = c - '0'; // Convert character to integer
            if(digit != 0 ) // Ensure we don't remove a digit that results in a negative index
            {
                dp[i] = min(dp[i], dp[i - digit] + 1); // Update the dp array with the minimum operations
            }
        }
    }
    cout<< dp[n] << endl; // Output the minimum operations to reduce n to 0
    return 0;
}