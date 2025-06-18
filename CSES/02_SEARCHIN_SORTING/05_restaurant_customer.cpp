#include <bits/stdc++.h>
#define mod ((int)1e9+7)
using namespace std;
typedef long long ll;
void solve()
{
    ll n;
    cin >> n;
    ll  ans=0,maxx=0;
    map<ll, ll> m;
    for(ll i=0;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        m[a]++;
        m[b]--;
    }

    for(auto it: m)
    {
        ans += it.second;
        maxx = max(maxx, ans);
    }
    cout<< maxx << endl;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t=1;
    while(t--)
    {
       solve();
    }
    return 0;
}