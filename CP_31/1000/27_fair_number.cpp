#include <bits/stdc++.h>
using namespace std;

bool isFair(long long n)
{
    long long num=n;
    while(num!=0)
    {
        int r=num%10;
        if(r!=0 && n%r!=0)
        {
            return false;
        }
        num/=10;
    }
    return true;
}


int main()
{
    long long t;
    cin>> t;
    while(t--)
    {
       long long n;
       cin>>n;
       while(!isFair(n))
       {
        n+=1;
       }
       cout<<n<<endl;
    }
    return 0;
}