#include<bits/stdc++.h>
using namespace std;
int n;
int dp[21][10001];
int solve(vector<int>&weights,int total,int currSum,int index)
{
    if(index>=n)
    {
        return abs(total-2*currSum);
    }
    if(dp[index][currSum]!=-1)
    {
        return dp[index][currSum];
    }
    //include
    int include=solve(weights,total,currSum+weights[index],index+1);
    //exclude
    int exclude=solve(weights,total,currSum,index+1);
    return dp[index][currSum]= min(include,exclude);
    
}
int minDifference(vector<int>&weights)
{
    memset(dp,-1,sizeof(dp));
    int totalWeights=accumulate(weights.begin(),weights.end(),0);
    return solve(weights,totalWeights,0,0);
}

int main()
{

    cin>>n;
    vector<int>weights(n);
    for(int i=0;i<n;i++)
    {
        cin>>weights[i];
    }
    cout<<minDifference(weights);
    return 0;
}