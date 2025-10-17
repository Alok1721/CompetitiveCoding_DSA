#include <bits/stdc++.h>
using namespace std;
vector<int>findCircularEle(vector<int>&arr,int k)
{
    vector<int>result;
    int n=arr.size();
    if(k<0)
    {
        k=-k;
        reverse(arr.begin(),arr.end());
        vector<int>prefix(n+k,0);
        prefix[0]=arr[0];
        for(int i=1;i<n+k;i++)
        {
            prefix[i]=prefix[i-1]+arr[i%n];
        }
        for(int i=0;i<n;i++)
        {
            result.push_back(prefix[i+k]-prefix[i]);
        }
        reverse(result.begin(),result.end());
    }
    else
    {
        vector<int>prefix(n+k,0);
        prefix[0]=arr[0];
        for(int i=1;i<n+k;i++)
        {
            prefix[i]=prefix[i-1]+arr[i%n];
        }
        for(int i=0;i<n;i++)
        {
            result.push_back(prefix[i+k]-prefix[i]);
        }
    }
    return result;
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
    vector<int>result=findCircularEle(arr,k);
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
    return 0;
}
