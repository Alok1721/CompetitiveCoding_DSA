#include <bits/stdc++.h>
using namespace std;



int main()
{
    long long t;
    cin>> t;
    while(t--)
    {
       long long n,k,q;
       cin>>n>>k>>q;
       vector<long long>a(n);
       for(int i=0;i<n;i++)
       {
        cin>>a[i];
        a[i]=(a[i]>q)?0:1;
       }

       long long cout_of_1s=0;
       long long ways=0;
       for(int i=0;i<n;i++)
       {
        if(a[i]==1)
        {
            cout_of_1s++;
        }
        else
        {
            if(cout_of_1s>=k)
            {
                long long diff=cout_of_1s-k+1;
                ways+=((diff*(diff+1))/2);
            }
            cout_of_1s=0;
        }
       }
       if(cout_of_1s>=k)
       {
            long long diff=cout_of_1s-k+1;
            ways+=((diff*(diff+1))/2);
       }
       cout<<ways<<endl;
    }
    return 0;
}