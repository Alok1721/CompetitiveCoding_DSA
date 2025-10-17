#include <bits/stdc++.h>
using namespace std;
int findMinLenthToConnectAllServer(vector<int>&dis,vector<int>&status)
{
    int n=status.size();
    int i=0,j=0;//i for status 0 and j for status 1
    int ans=0;
    while(j<n)
    {
        //j-1 && i track  position of 1
        i=j;
        while(i+1<n&& status[i]==status[i+1] )//always move i+1 if status==0
        {
            i++;
        } 
        if(status[j]==1) //find the next group
        {
            j=i+1;
            continue;
        }
        int maxdist=0;
        int sum=0;
        for(int k=j-1;k<=i;k++) //finding the max distance between two 1s and also finding the maximum distance from either side
        {
            if(k>=0 && k<n && k+1<n)
            {maxdist=max(maxdist,dis[k+1]-dis[k]);
            sum+=dis[k+1]-dis[k];}
        }

        if(j-1==-1 || j+1==n)
        {
            ans+=sum;//if only one end there donot subtract the maxdist because it will going to need that much length 
        }
        else
        {
            ans+=sum-maxdist;// add the length wherever possible 
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