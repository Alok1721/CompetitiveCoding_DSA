#include <bits/stdc++.h>
using namespace std;



int main()
{
    int t;
    cin>> t;
    while(t--)
    {
       int64_t n;
       cin>>n;
       while(n%2==0)
       {
        n/=2;
        
       }
       if(n>1)cout<<"YES"<<endl;
       else cout<<"NO"<<endl;
    }
    return 0;
}