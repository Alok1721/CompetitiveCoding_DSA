#include<bits/stdc++.h>
using namespace std;

long long findCombineSlimeCost(vector<int>&slimes)
{
    int n=slimes.size();
    sort(slimes.begin(),slimes.end());
    long long cost=0;
    // for(auto it:slimes)
    // {
    //     cout<<it<<" ";
    // }

    while(slimes.size()>1)
    {
        sort(slimes.begin(),slimes.end());
        auto first=slimes.begin();
        auto last=slimes.end()-1;
        int temp_cost=0;
        int new_slime=0;
        if((*first + *(first+1))%100 <(*last+*(last-1))%100 )
        {
            
            temp_cost=(*first)*(*(first+1));
            new_slime=((*first)+(*(first+1)))%100;
            slimes.erase(first);
            auto pos=slimes.begin();
            slimes.erase(pos);
            slimes.push_back(new_slime);
        }
        else
        {
            temp_cost=(*last)*(*(last-1));
            new_slime=((*last)+(*(last-1)))%100;
            slimes.erase(last);
            auto pos=slimes.end()-1;
            slimes.erase(pos);
            slimes.push_back(new_slime);
        }
        cost+=temp_cost;
        for(auto it:slimes)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        
    }
    // for(auto it:slimes)
    // {
    //     cout<<it<<" ";
    // }
    return cost;

}


int main()
{

    int n;
    cin>>n;
    vector<int>slimes(n);
    for(int i=0;i<n;i++)
    {
        cin>>slimes[i];
    }
    cout<<findCombineSlimeCost(slimes);

    return 0;
}