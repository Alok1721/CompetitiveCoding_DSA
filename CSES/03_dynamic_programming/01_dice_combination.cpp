#include <bits/stdc++.h>
#define mod ((int)1e9+7)
using namespace std;

vector<int> dp(1000000);
int findCombination(int n,vector<int>&dp)
{
    if(n==0)return 1;
    if(n<0)return 0;
    if(dp[n]!=-1)return dp[n];
    long long ans=0;
    for(int i=1;i<=6;i++)
    {
        ans=(ans+findCombination(n-i,dp))%mod;
    }
    return dp[n]=ans;

}

int main()
{
    int n;
    cin>> n;
    vector<int>dp(n+1,-1);
    cout<<findCombination(n,dp)<<endl;
    return 0;
}