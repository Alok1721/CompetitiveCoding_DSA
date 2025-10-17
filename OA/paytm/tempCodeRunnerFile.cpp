// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int>&transaction,int balance,int ind,int n,vector<vector<int>>&dp){
    if(ind>=n){
        return 0;
    }
    
    if(dp[ind][balance]!=-1){
        return dp[ind][balance];
    }
    
    int take=-1e9;
    if(balance+transaction[ind]>=0){
        take=0;
        take=1+solve(transaction,balance+transaction[ind],ind+1,n,dp);
    }
    
    int notTake=solve(transaction,balance,ind+1,n,dp);
    
    return dp[ind][balance]=max(take,notTake);
}

int main() {
    // Write C++ code here
    vector<int>transaction;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        transaction.push_back(a);
    }
    
    
    int ps=0;
    for(int i=0;i<n;i++){
        if(transaction[i]>0){
            ps+=transaction[i];
        }
    }
    
    int balance =0;
    vector<vector<int>>dp(n,vector<int>(ps+1,-1));
    
    int ans=solve(transaction,balance,0,n,dp);
    
    cout<<ans<<endl;

    return 0;
}