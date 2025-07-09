#include <bits/stdc++.h>
#define mod ((int)1e9+7)
using namespace std;



int main()
{
    long long t;
    cin>> t;
    while(t--)
    {
       int n,k;
       cin>>n>>k;

       int result=1;
       for(int i=1;i<n;i++)
       {
        result+= k;
       }
       cout<<result<<endl;
    }
    return 0;
}