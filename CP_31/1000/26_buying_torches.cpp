#include <bits/stdc++.h>
using namespace std;

long long ceil_division(long long a,long long b)
{
    return (a+b-1)/b;
}


int main()
{
    long long t;
    cin>> t;
    while(t--)
    {
       long long x,y,k;
       cin>>x>>y>>k;

       long long sticks_gained_per_trade=x-1;
       long long sticks_needed=k*y+k-1; //k*y goes for coal k for k sticks and -1 for extra that we having 1 in starting of 
       long long trades=0;
       trades+=ceil_division(sticks_needed,sticks_gained_per_trade);
       trades+=k;//because k coal generated from k*y sticks that we already gained from trades
       cout<<trades<<endl;

    }
    return 0;
}