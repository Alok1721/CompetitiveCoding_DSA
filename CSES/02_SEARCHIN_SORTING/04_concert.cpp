#include <bits/stdc++.h>
#define mod ((int)1e9+7)
using namespace std;



int main()
{
    int m,n;
    cin>>n>>m;
    multiset<long long > pricesTicket;
    vector<long long > maxPrices(m);
    for(int i=0;i<n;i++)
    {
        long long temp;
        cin>>temp;
        pricesTicket.insert(temp);
    }
    for(int i=0;i<m;i++)
    {
        cin>>maxPrices[i];
    }
    for(int i=0;i<m;i++)
    {
        auto it=pricesTicket.upper_bound(maxPrices[i]);
        if(it==pricesTicket.begin())
        {
            cout<<-1<<endl;
            continue;
        }else{
            cout<<*(--it)<<endl;
            pricesTicket.erase(it);
        }
    }


    return 0;
}