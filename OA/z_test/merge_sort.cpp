#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>&arr,int low,int mid,int high)
{
    int n1=mid-low+1;
    int n2=high-mid;
    vector<int>left(n1);
    vector<int>right(n2);
    for(int i=0;i<n1;i++)left[i]=arr[low+i];
    for(int i=0;i<n2;i++)right[i]=arr[mid+1+i];

    int i=0;
    int j=0;
    int k=low;
    while(i<n1 && j<n2)
    {
        if(left[i]<right[j])arr[k++]=left[i++];
        else arr[k++]=right[j++];
    }
    while(i<n1)
    {
        arr[k++]=left[i++];
    }
    while(j<n2)
    {
        arr[k++]=right[j++];
    }
    
}
void mergeSort(vector<int>&arr,int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
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

    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}