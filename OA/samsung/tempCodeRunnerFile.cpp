#include<bits/stdc++.h>
using namespace std;

int minCostToReach(vector<int>&camelCost)
{
    int n=camelCost.size();
    multiset<int>mt(camelCost.begin(),camelCost.end());
    bool isSmall=true;
    int totalCost=0;
    priority_queue<int,vector<int>,greater<int>>pq;
    while(true)
    {
        int a,b;
        if(isSmall)
        {
            auto it=mt.begin();
            a=*it;it= mt.erase(it);
            b=*it;mt.erase(it);
        }
        else
        {
            auto it=prev(mt.end());
            a=*it;mt.erase(it);
            it=prev(mt.end());
            b=*it;mt.erase(it);
        }
        
        
        pq.push(a);
        pq.push(b);
        if(mt.empty())
        {
            totalCost+=max(a,b);
            break;
        }
        else
        {
            totalCost+=max(a,b);
            totalCost+=pq.top();
            pq.pop();
            isSmall=!isSmall;
        }
        cout<<a<<" "<<b <<" "<<totalCost<<endl;
    }
    return totalCost;

}

int main()
{

    int n;
    cin>>n;
    vector<int>camelCost(n);
    for(int i=0;i<n;i++)
    {
        cin>>camelCost[i];
    }
    cout<<minCostToReach(camelCost)<<endl;
    return 0;
}