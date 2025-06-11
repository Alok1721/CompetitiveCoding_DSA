#include <bits/stdc++.h>
using namespace std;



int main()
{
    long long t;
    cin>> t;
    while(t--)
    {
       long long n;
       cin >> n;
       if(n<4 || n%2==1)
       {
        cout<<-1<<endl;
       }
       else
       {
        long long minB=(n+5)/6;
        long long  maxB=n/4;
        cout<<minB<<" "<<maxB<<endl;
       }
    }
    return 0;
}