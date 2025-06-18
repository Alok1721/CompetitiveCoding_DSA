#include <bits/stdc++.h>
using namespace std;



int main()
{
    int t;
    cin>> t;
    while(t--)
    {
       long long m,n,i,j;
       cin>>m>>n>>i>>j;
       map<pair<long,long>,pair<long,long>>mp;
       mp[{1,1}]={m,n};mp[{1,n}]={m,1};
       mp[{m,n}]={1,1};mp[{m,1}]={1,n};

       long long res=LLONG_MIN;
       vector<pair<long long,long long>> dirs={{1,1},{1,n},{m,1},{m,n}};
       long long x=1,y=1;
       for(auto dir:dirs)
       {
        long long temp=abs(dir.first-i)+abs(dir.second-j);
        if(temp>res)
        {
            x=dir.first;
            y=dir.second;
            res=temp;
        }
       }
       
       cout<<x<<" "<<y<<" "<<mp[{x,y}].first<<" "<<mp[{x,y}].second<<endl;
       

    }
    return 0;
}