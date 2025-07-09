#include <bits/stdc++.h>
using namespace std;

pair<long long,vector<long long>> findMinVist(vector<long long >&visits)
{
    long long n=visits.size();
    vector<pair<long long,long long>> building_map;
    for(long long i=0;i<n;i++)
    {
        building_map.push_back({visits[i],i});
    }   

    sort(building_map.rbegin(),building_map.rend());
    vector<long long> result(n+1,0);
    result[0]=0;

    long long minutes=0;
    long long coordinate=1;
    for(long long i=0;i<n;i++)
    {
        result[building_map[i].second+1]=coordinate;
        minutes+=(2*abs(coordinate)*building_map[i].first);
        if(coordinate<0)
        {
            coordinate=abs(coordinate)+1;
        }else
        {
            coordinate=-coordinate;
        }
    }

    return {minutes,result};

}

int main()
{
    long long t;
    cin>> t;
    while(t--)
    {
        long long n;
        cin>>n;
        vector<long long> visits(n);
        for(long long i=0;i<n;i++)
        {
            cin>>visits[i];
        }
        auto result=findMinVist(visits);
        cout<<result.first<<endl;
        for(long long i=0;i<result.second.size();i++)
        {
            cout<<result.second[i]<<" ";
        }
        cout<<endl;
       
    }
    return 0;
}