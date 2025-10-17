#include <bits/stdc++.h>
using namespace std;
int findMinLenthToConnectAllServer(vector<int>&dis,vector<int>&status)
{
    int n=status.size();
    int i=0,j=0;//i for status 0 and j for status 1
    int ans=0;
    while(j<n)
    {
        i=j;
        while(i+1<n&& status[i]==status[i+1] )
        {
            i++;
        } 
        if(status[j]==1)
        {
            j=i+1;
            continue;
        }
        int maxdist=0;
        int sum=0;
        for(int k=j-1;k<=i;k++)
        {
            if(k>=0 && k<n && k+1<n)
            {maxdist=max(maxdist,dis[k+1]-dis[k]);
            sum+=dis[k+1]-dis[k];}
        }

        if(j-1==-1 || j==n)
        {
            ans+=sum;
        }
        else
        {
            ans+=sum-maxdist;
        }
        j=i+1;
    }
    return ans;
}
int main()
{

    int n;
    cin>>n;
    vector<int>dis(n),status(n);
    for(int i=0;i<n;i++)
    {
        cin>>status[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>dis[i];
    }
    cout<<findMinLenthToConnectAllServer(dis,status);
    return 0;
}