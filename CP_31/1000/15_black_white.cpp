#include <bits/stdc++.h>
using namespace std;

int countExtraBlack(string&s, long long k)
{
    int n=s.size();
    int w_count=0;

    for(int i=0;i<k;i++)
    {
        if(s[i]=='W')w_count++;

    }

    int min_w=w_count;

    for(int i=k;i<n;i++)
    {
        if(s[i-k]=='W')w_count--;
        if(s[i]=='W')w_count++;
        min_w=min(min_w,w_count);
    }

    return min_w;
}

int main()
{
    long long t;
    cin>> t;
    while(t--)
    {
        long long n,k;
        cin>>n>>k;
        string stripe;
        cin>>stripe;

        cout<<countExtraBlack(stripe,k)<<endl;

       
    }
    return 0;
}