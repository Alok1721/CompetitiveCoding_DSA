#include<bits/stdc++.h>

using namespace std;

int findLIS(vector<int>&piles)
{
    int n=piles.size();
    vector<int>dp(n,1);
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(piles[i]>piles[j])
            {
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    return *max_element(dp.begin(),dp.end());
    
}

int findMinimumShift(vector<int>&piles,int n)
{
    int lis=findLIS(piles);
    return n-lis;
    
}
int main ()
{
    int n;
    cin>>n;
    vector<int>piles(n);
    for(int i=0;i<n;i++)
    {
        cin>>piles[i];
    }
    
    cout<<findMinimumShift(piles,n);

    return 0;
}