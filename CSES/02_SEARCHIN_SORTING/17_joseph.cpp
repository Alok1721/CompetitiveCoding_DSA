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
        long long n;
        cin>>n;
        queue<ll> q;
        for(ll i=1;i<=n;i++)
        {
            q.push(i);
        }
        vector<ll> result;
        bool toggle=true;

        while(!q.empty())
        {
            if(toggle)
            {
                q.push(q.front());
                q.pop();
                
                result.push_back(q.front());
                q.pop();
            }
            
        }
        for(ll i=0;i<n;i++)
        {
            cout<<result[i]<<" ";
        }
       
    }
    return 0;
}