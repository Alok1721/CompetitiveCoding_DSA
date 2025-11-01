#include <bits/stdc++.h>
using namespace std;
int findMaxDiff(vector<int>arr)
{
 
    int n=arr.size();
    int minE=arr[0];
    int maxDiff=-1;
    for(int i=0;i<n;i++)
    {

        if(arr[i]<=minE)
        {
            minE=arr[i];
        }
        else if(arr[i]-minE>maxDiff)
        {
            maxDiff=arr[i]-minE;
        }
    }
    return maxDiff;
}

int main() {
 
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<findMaxDiff(arr);


    return 0;
}