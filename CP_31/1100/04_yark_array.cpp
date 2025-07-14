#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    long long t;
    cin>> t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll>v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }

        ll ans=INT_MIN;
        int i=0;int j=0;
        ll sum=0;
        while(j<n)
        {
            if(sum<0)
            {
                sum=0;//negative number found so, put sum=0;
                i=j;
            }

            if(i<j)
            {
                if((v[j]^v[j-1])&1)
                {
                    sum+=v[j];
                }
                else
                {
                    sum=v[j];//new start
                    i=j;
                }
            }else
            {
                sum=v[j];
            }
            ans=max(ans,sum);
            j++;
        }
        cout<<ans<<endl;
    }
    return 0;
}