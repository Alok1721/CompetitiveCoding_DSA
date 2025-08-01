#include<bits/stdc++.h>
using namespace std;

int findMaxMultiple(vector<int>&arr,int m,int k)
{
    int n=arr.size();
    vector<int>remainder(n);
    for(int i=0;i<n;i++)
    {
        remainder[i]=arr[i]%m;
    }
    sort(remainder.begin(),remainder.end());
    int maxMultiple=0; //less and equal to k
    for(int i=0;i<n;i++)
    {
        if(remainder[i]+maxMultiple<=k)
        {
            maxMultiple+=remainder[i];
        }
    }
    return maxMultiple;
}


int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<findMaxMultiple(arr,m,k)<<endl;



    
    return 0;
}