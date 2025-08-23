#include<bits/stdc++.h>
using namespace std;
int maxReward(vector<int>&reward1,vector<int>&reward2,int k,int n,int m)
{
    int max_reward=0;
    vector<pair<int,int>>reward;
    for(int i=0;i<n;i++)
    {
        reward.push_back({reward1[i],reward2[i]});
    }
    sort(reward.begin(),reward.end(),[](auto &a,auto &b)
{
     if(abs(a.first-a.second)==abs(b.first-b.second))
     {
        return a.first>b.first;
     }
     return abs(a.first-a.second)>abs(b.first-b.second);
});
int i=0;
while(i<n-k)
{
    if(reward[i].first>reward[i].second)
    {
        max_reward+=reward[i].first;
        k--;
    }else
    {
        max_reward+=reward[i].second;
    }
    i++;
}
while(k>0)
{
    max_reward+=reward[i].first;
    k--;
    i++;
}
return max_reward;
}
int main()
{
    int k;
    cin>>k;
    int n;
    cin>>n;
    vector<int>reward1(n);
    for(int i=0;i<n;i++)
    {
        cin>>reward1[i];
    }
    int m;
    cin>>m;
    vector<int>reward2(n);
    for(int i=0;i<m;i++)
    {
        cin>>reward2[i];
    }
    cout<<maxReward(reward1,reward2,k,n,m);//when k task will done by person1 excatly
    
    
    return 0;
}