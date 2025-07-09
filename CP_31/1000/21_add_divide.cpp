#include <bits/stdc++.h>
using namespace std;



int main()
{
    long long t;
    cin>> t;
    while(t--)
    {
       long long a,b;
       cin>>a>>b;

       long long ans=INT_MAX;
       for(int add=0;add<32;add++)
       {
        long long ops=add;
        long long new_b=b+add;
        if(new_b==1)
        {
            continue;
        }
        long long copy_a=a;
        while(copy_a>0)
        {
            copy_a/=new_b;
            ops++;
        }

        ans=min(ans,ops);
       }
       cout<<ans<<endl;
    }
    return 0;
}