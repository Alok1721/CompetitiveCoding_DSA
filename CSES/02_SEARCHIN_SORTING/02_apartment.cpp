#include <bits/stdc++.h>
#define mod ((int)1e9+7)
using namespace std;



int main()
{
    long long n,m,k;
    cin>>n>>m>>k;
    vector<int> a(n);
    vector<int> b(m);

    for(int i=0;i<n;i++)//clients_desire_size
    {
        cin>>a[i];
    }
    for(int i=0;i<m;i++)//available_apartment_size
    {
        cin>>b[i];
    }
    
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    long long ans=0;
    long long i=0,j=0;
    while(i<n && j<m)
    {
        if(a[i]-k<=b[j]&& b[j]<=a[i]+k)
        {
            ans++;
            i++;
            j++;
        }
        else if(a[i]+k<b[j])
        {
            i++;
        }
        else if(b[j]<a[i]-k)
        {
            j++;
        }

    }
    cout<<ans<<endl;
    return 0;
}