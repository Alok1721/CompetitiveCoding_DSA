#include <bits/stdc++.h>
#define mod ((int)1e9+7)
using namespace std;
long long findSmallestsum(vector<long long >&coins)
{
    sort(coins.begin(),coins.end());
    long long target=1;
    for(auto coin:coins)
    {
        if(coin<=target)
        {
            target+=coin;
        }else
        {
            break;
        }
    }
    return target;
}


int main()
{
    int t;
     t=1;
    while(t--)
    {
       int n;
       cin>>n;vector<long long>coins(n);
       for(int i=0;i<n;i++)

       {
        cin>>coins[i];
       }
       cout<<findSmallestsum(coins)<<endl;
       
    }
    return 0;
}