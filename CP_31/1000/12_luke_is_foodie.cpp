#include <bits/stdc++.h>
using namespace std;



int main()
{
    long long t;
    cin>> t;
    while(t--)
    {
       long long n,x;
       cin>>n>>x;
       vector<long long>a(n);
       for(long long i=0;i<n;i++) 
       {
        cin>>a[i];
       }

       vector<pair<long long,long long>>segments(n);
       for(int i=0;i<n;i++)
       {
        segments[i]={a[i]-x,a[i]+x};
       }

       //step2:define the lr and find discontinutiy of l>r
       long long l=segments[0].first;
       long long r=segments[0].second;
       long long count=0;

       for(int i=1;i<n;i++)
       {
        l=max(segments[i].first,l);
        r=min(segments[i].second,r);

        if(l>r)
        {
            count++;
            l=segments[i].first;
            r=segments[i].second;
        }
       }
       cout<<count<<endl;
    }
    return 0;
}