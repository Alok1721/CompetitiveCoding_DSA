#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve() {
   ll n,c;
   cin>>n>>c;
   vector<ll> a(n);
    for(int i=0;i<n;i++) {
         cin>>a[i];
    }

    ll l=1,r=1e9,ans=-1;
    while(l<=r) {
        ll mid=l+(r-l)/2;
        ll sum_all=0;
        for(int i=0;i<n;i++)
        {
            sum_all+=(a[i]+2*mid)*(a[i]+2*mid);
            if(sum_all>c) {
                break; // No need to continue if sum exceeds c
            }
        }
        if(sum_all<=c)
        {
            ans=mid;
            l=mid+1; // Try for a larger value
        }
        else {
            r=mid-1; // Try for a smaller value
        }
        
    }
    cout << ans << endl;
}


int main()
{
    long long t;
    cin>> t;
    while(t--)
    {solve();
    }
    return 0;
}