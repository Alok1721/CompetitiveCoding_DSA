#include <bits/stdc++.h>
using namespace std;

int findMinCost(vector<int>&a)
{
    int n=a.size();
    int ans=INT_MAX;
    for(int i=0;i<n;i++)
    {
        int temp=abs(0-a[i]);
        ans=min(ans,temp);
    }
    return ans;
}

int main()
{
    int t;
    cin>> t;
    vector<int> a(t);
    for(int i=0;i<t;i++)
    {
        cin>> a[i];
    }

    cout<<findMinCost(a)<<endl;
    return 0;
}