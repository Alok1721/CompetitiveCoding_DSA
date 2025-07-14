#include <bits/stdc++.h>
const int mod =1e9+7;
using namespace std;
typedef long long ll;




int main()
{
    int t;
    t=1;
    while(t--)
    {
        int n;
        cin>>n;

        vector<vector<int>>customer(n);
        for(int i=0;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            customer[i]={a,b,i};
        }

        sort(customer.begin(),customer.end());

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        int room_count=0;
        vector<int>result(n);
        for(auto curr:customer)
        {
            int arr=curr[0];
            int dep=curr[1];
            int idx=curr[2];
            if(!pq.empty()&& pq.top().first<arr)
            {
                auto checkOut=pq.top();
                int room_no=checkOut.second;
                pq.pop();
                pq.push({dep,room_no});
                result[idx]=room_no;
            }
            else
            {
                room_count++;
                pq.push({dep,room_count});
                result[idx]=room_count;
            }

        }
        cout<<room_count<<endl;

        for(auto it:result)cout<<it<<" ";
        cout<<endl;
       
    }
    return 0;
}