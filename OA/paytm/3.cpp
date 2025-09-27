#include <bits/stdc++.h>
using namespace std;
vector<int>findSum(vector<int>&nums1,vector<int>&nums2)
{
    int m=nums1.size();
    int n=nums2.size();
    vector<int>result;
    int carry=0;
    while(m>0 && n>0)
    {
        int sum=nums1[m-1]+nums2[n-1]+carry;
        carry=sum/10;
        sum=sum%10;
        result.push_back(sum);
        m--;
        n--;
    }
    while(m>0)
    {
        int sum=nums1[m-1]+carry;
        carry=sum/10;
        sum=sum%10;
        result.push_back(sum);
        m--;
    }    
    while(n>0)
    {
        int sum=nums2[n-1]+carry;
        carry=sum/10;
        sum=sum%10;
        result.push_back(sum);
        n--;
    }
    if(carry>0)
    {
        result.push_back(carry);
    }
    reverse(result.begin(),result.end());
    return result;
}
int main()
{
    int m,n;
    cin>>m>>n;
    vector<int>arr(m),brr(n);
    for(int i=0;i<m;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>brr[i];
    }
    vector<int>result=findSum(arr,brr);
    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }
    return 0;
}