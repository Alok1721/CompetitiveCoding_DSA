#include <bits/stdc++.h>
using namespace std;

int findOperations(vector<long long>&a,long long n,long long k)

{
    long long ans=LLONG_MAX;
    long long  even_count=0;
    for(long long i=0;i<n;i++)
    {
        if(a[i]%2==0)
        {
            even_count++;
        }
    }
    
    for(long long i=0;i<n;i++)
    {
        // cout<<a[i]<<" ";
        if(a[i]%k==0)
        {
            ans=0;
        }
        ans=min(ans,(k-(a[i]%k)));
        // cout<<"mi/nR"<<minR<<endl;
    }
    // cout<<"minR"<<minR<<endl;
    if(k==4)
    {
        if(even_count>=2)
        {
            ans=min(ans, 0LL);
        }
        else if(even_count==1)
        {
            ans=min(ans, 1LL);
        }
        else if(even_count==0)
        {
            ans=min(ans, 2LL);
        }
       
    }
    return ans;
}

int main()
{
    long long t;
    cin>> t;
    while(t--)
    {
        long long n,k;
        cin >> n >> k;
        vector<long long > a(n);
        for(long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout<<findOperations(a, n, k) << endl;
       
    }
    return 0;
}