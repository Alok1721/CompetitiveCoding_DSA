#include<bits/stdc++.h>
using namespace std;

int findLastPerson(int n,int k)
{
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        arr[i]=i;
    }
    // int n=arr.size();
    int index=k-1;
    arr.erase(arr.begin()+index);
    while(arr.size()!=1)
    {
           index=(index+k-1)%arr.size();
           arr.erase(arr.begin()+index);
    }
    return arr[0];
}



int main()
{
    int n,k;
    cin>>n>>k;
    cout<<findLastPerson(n,k);
    return 0;
}