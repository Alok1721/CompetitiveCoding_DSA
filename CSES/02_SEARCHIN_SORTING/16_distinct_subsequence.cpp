#include <bits/stdc++.h>
const int mod =1e9+7;
using namespace std;
typedef long long ll;
ll distinctValueSubsequence(vector<ll> &a)
{
    ll n=a.size();
    vector<ll>dp(n+1);
    dp[0]=1;
    unordered_map<ll,ll>count;

    for(ll i=1;i<=n;i++)
    {
        dp[i]=(2*dp[i-1])%mod;
        if(count.count(a[i-1]))
        {
            ll j=count[a[i-1]];
            dp[i]=(dp[i]-dp[j-1]+mod)%mod;
        }
        count[a[i-1]]=i;
    }
    return (dp[n]-1+mod)%mod;
}


int main()
{
    int t;
    t=1;
    while(t--)
    {
       long long n;
       cin>>n;
       vector<ll> elements(n);
       for(int i=0;i<n;i++)
       {
        cin>>elements[i];
       }

       cout<<distinctValueSubsequence(elements)<<endl;
    }
    return 0;
}