#include <bits/stdc++.h>
#define mod ((int)1e9+7)
using namespace std;

long long findCombination(long long x,vector<long long>&coin,vector<long long >&dp)
{
    if(x==0)return 1;
    if(x<0)return 0;

    if(dp[x]!=-1)return dp[x];

    long long ans=0;
    for(int i=0;i<(int)coin.size();i++)
    {
        ans=(ans+findCombination( x-coin[i],coin,dp))^;//counting the coin needed
    }
    return dp[x]=ans;

}

int main()
{
    long long n,x;
    cin>> n>>x;
    vector<long long>dp(x+1,-1);
    vector<long long> coin(n);
    dp[0]=1;
    for(int i=0;i<n;i++)
    {
        cin>>coin[i];
    }
    long long  result=findCombination(x,coin,dp);
    // result=result==INT_MAX?-1:result;
    cout<<result<<endl;
    return 0;
}