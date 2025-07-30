#include<bits/stdc++.h>
using namespace std;

int findCake(vector<int>&arr,int k)
{
    int n=arr.size();
    vector<pair<int,int>>cakes;//cake_no,index
    for(int i=0;i<n;i++)
    {
        cakes.push_back({arr[i],i+1});
    }

    sort(cakes.begin(),cakes.end());
    vector<int>cake_index;
    for(int i=0;i<k;i++)
    {
        cake_index.push_back(cakes[i].second);
    }
    sort(cake_index.begin(),cake_index.end());
    return cake_index[k-1]-cake_index[0]+1;
    
}
int main()
{

    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    cout<<findCake(arr,k)<<endl;
    return 0;
}