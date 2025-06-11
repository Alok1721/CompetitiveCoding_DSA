#include <bits/stdc++.h>
using namespace std;



int main()
{
    int t;
    cin>> t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<long long> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        //count ones and zeros
        long long zeroC=0;
        long long oneC=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==1)
            {
                oneC++;
            }else if(a[i]==0)
            {
                zeroC++;
            }
        }
        long long ans=pow(2,zeroC)*oneC;
        cout<<ans<<endl;
       
    }
    return 0;
}