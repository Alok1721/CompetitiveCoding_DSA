#include <bits/stdc++.h>
using namespace std;



int main()
{
    long long t;
    cin>> t;
    while(t--)
    {
       string a,b;
       cin>>a>>b;
       int m=a.size();
       int n=b.size();
       int result=0; 
       for(int len=1;len<=min(m,n);len++)
       {
        for(int i=0;i<=m-len;i++)
        {
            for(int j=0;j<=n-len;j++)
            {
                string suba=a.substr(i,len);
                string subb=b.substr(j,len);

                if(suba==subb)
                {
                    result=max(result,len);
                }
            }
        }

        
       }
       cout<<n+m-2*result<<endl;
    }
    return 0;
}