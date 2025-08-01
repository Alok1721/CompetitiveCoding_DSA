#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    long long t;
    cin>> t;
    while(t--)
    {
        ll n,q;
        cin >> n >> q;
        vector<ll> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<ll> qu(q);
        for(int i = 0; i < q; i++)
        {
            cin >> qu[i];
        }

        ll prev=31;
        for(int i=0;i<q;i++)
        {
            if(qu[i]>=prev)continue;
            ll val=pow(2,qu[i]);
            for(int j=0;j<n;j++)
            {
                if(a[j]%val==0)
                {
                    a[j]+=val/2;//after that no query greater then a[j] will be able to divide it
                }
            }
            prev=qu[i];
        }
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout << endl;

    }
    return 0;
}