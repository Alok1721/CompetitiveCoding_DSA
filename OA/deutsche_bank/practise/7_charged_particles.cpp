#include<bits/stdc++.h>
using namespace std;

int pairDistance(int a,int b)
{
    if(a==b)
    {
        return 2;
    }else
    {
        return 1;
    }
}
vector<int> findDistance(vector<int>&arr,vector<int>&query)
{
    int n=arr.size();
    int q=query.size();
    vector<int>result;
    int totalDistance=0;
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]==arr[i+1])
        {
            totalDistance+=2;
        }else
        {
            totalDistance+=1;
        }
    }

    for(auto idx:query)
    {
        if(idx>0)
        {
            totalDistance-=pairDistance(arr[idx],arr[idx-1]);
        }
        if(idx<n-1)
        {
            totalDistance-=pairDistance(arr[idx],arr[idx+1]);
        }
        arr[idx]=!arr[idx];
        if(idx>0)
        {
            totalDistance+=pairDistance(arr[idx],arr[idx-1]);
        }
        if(idx<n-1)
        {
            totalDistance+=pairDistance(arr[idx],arr[idx+1]);
        }
        result.push_back(totalDistance);
    }
    return result;
}


int main()
{
    int n,q;
    cin>>n>>q;
    vector<int>arr(n);//same charge distance 2 and different charge distance 1
    vector<int>query(q);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<q;i++)
    {
        int x;
        cin>>x;//these index will toggle
        query[i]=x-1;//0 based indexing
    }

    vector<int>result=findDistance(arr,query);
    for(int i=0;i<q;i++)
    {
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;

}