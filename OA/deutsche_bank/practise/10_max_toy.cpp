#include<bits/stdc++.h>
using namespace std;

int maxToys(vector<int>&x,vector<int>&toys,int k,int p)
{
    int n=x.size();
    //using sliding window find max in the window and pop the element when its distance is greater than k
    vector<pair<int,int>>shops;
    for(int i=0;i<n;i++)
    {
        shops.push_back({x[i],toys[i]});
    }
    sort(shops.begin(),shops.end());
    int i=0;
    int j=0;
    int maxToys=0,currToys=0;
    while(j<n)
    {
        currToys+=shops[j].second;
        while(i<=j)
        {
            int l=shops[i].first;
            int r=shops[j].first;
            int dist=min(abs(p-l)+(r-l),abs(p-r)+(r-l));
            if(dist>k)
            {
                currToys-=shops[i].second;
                i++;
            }else
            {
                break;
            }
            

        }
        maxToys=max(maxToys,currToys);
        j++;
    }
    return maxToys;
    
}

int main()
{
    int n,k,p;
    cin>>n>>k>>p;
    vector<int>x(n);
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
    }
    vector<int>toys(n);
    for(int i=0;i<n;i++)
    {
        cin>>toys[i];   
    }
    cout<<maxToys(x,toys,k,p)<<endl;
    
    return 0;
}