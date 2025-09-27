#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>&arr,int n,int i,int money)
{
    if(i>=n)return 0;
    int skip=0,take=0;//either skip present element or take it

    skip=solve(arr,n,i+1,money);
    if(arr[i]>=0)//incoming money
    {
        take=1+solve(arr,n,i+1,money+arr[i]);
    }
    else if(arr[i]<0 && money+arr[i]>=0)//outgoing money
    {
        take=1+solve(arr,n,i+1,money+arr[i]);
    }
    return max(skip,take);
}
int noOfTransaction(int n,vector<int>&arr)
{
    return solve(arr,n,0,0);   
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<noOfTransaction(n,arr);    
    return 0;
}
