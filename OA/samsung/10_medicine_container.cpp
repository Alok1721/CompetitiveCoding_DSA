#include<bits/stdc++.h>
using namespace std;
int findMinTrips(vector<int>&capacities,int target,int index)
{
    if(target==0)return 0;
    if(index>=capacities.size() || target<0)
    {
        return 1e7;
    }
    //include
    int include=1+findMinTrips(capacities,target-capacities[index],index);
    //exclude
    int exclude=findMinTrips(capacities,target,index+1);
    return min(include,exclude);
}


int main()
{
    int target,n;
    cin>>target>>n;
    vector<int>capacities(n);
    for(int i=0;i<n;i++)
    {
        cin>>capacities[i];
    }
    int ans=findMinTrips(capacities,target,0);
    if(ans==1e7)
    {
        cout<<-1;
        return 0;
    }
    cout<<ceil((double)ans/2);
    return 0;
}