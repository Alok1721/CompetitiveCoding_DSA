#include<bits/stdc++.h>
using namespace std;
int findStartingVillage(int village,vector<int>&energy,vector<int>&distance)
{
    int n=village;
    vector<int>capacity(n);
    for(int i=0;i<n;i++)
    {
        capacity[i]=energy[i]-distance[i];
    }

    int currentEnergy=0;
    int start=0;
    for(int i=0;i<n;i++)
    {
        currentEnergy+=capacity[i];
        if(currentEnergy<0)
        {
            currentEnergy=0;
            start=i+1;
        }
    }
    return start+1;
}


int main()
{

    int n;
    cin>>n;
    vector<int>energy(n);
    vector<int>distance(n);

    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>energy[i]>>distance[i];
    }
    cout<<findStartingVillage(n,energy,distance)<<endl;


    return 0;
}