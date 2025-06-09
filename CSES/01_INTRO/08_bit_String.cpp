#include <bits/stdc++.h>
#define mod ((int)1e9+7)
using namespace std;



int main()
{
    long long t;
    cin>> t;
    long long result=1;
    for(long long i=1;i<=t;i++)
    {
        result=(2*result)%mod;
    }
    cout<<result<<endl;
    return 0;
}