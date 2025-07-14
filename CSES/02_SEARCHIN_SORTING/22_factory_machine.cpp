#include <bits/stdc++.h>
const int mod =1e9+7;
using namespace std;
typedef long long ll;
bool canMake(ll time,vector<ll>&k,ll t)
{
    ll total=0;
    for(ll x:k)
    {
        total+=time/x;
        if(total>=t)return true;
    }
    return false;
}



int main()
{
    int t;
    t=1;
    while(t--)
    {
        ll n,t;
        cin>>n>>t;
        vector<ll> k(n);
        for(int i=0;i<n;i++)cin>>k[i];

        ll left=1;
        ll right=*max_element(k.begin(),k.end())*t;
        ll ans=right;

        while(left<=right)
        {
            ll mid=(left+right)/2;//hit and trail time
            if(canMake(mid,k,t))
            {
                ans=mid;
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }

        cout<<ans<<endl;
       
    }
    return 0;
}