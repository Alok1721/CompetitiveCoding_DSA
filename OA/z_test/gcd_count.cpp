#include<bits/stdc++.h>
using namespace std;

int findGCDCount(int l,int r,int g)
{
    int count=0;
    l=(l+g-1)/g;
    r=(r+g-1)/g;
    for(int i=l;i<=r;i++)
    {
        for(int j=i+1;j<=r;j++)
        {
            if(__gcd(i,j)==1)count++;
        }
    }
    return count;
}

int main()
{
    int l,r,g;
    cin>>l>>r>>g;
    cout<<findGCDCount(l,r,g);

    return 0;
}