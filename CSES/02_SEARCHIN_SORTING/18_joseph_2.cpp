#include <bits/stdc++.h>
const int mod =1e9+7;
using namespace std;
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;




int main()
{
    int t;
     t=1;
    while(t--)
    {
        long long n,k;
        cin>>n>>k;
        ordered_set<int> people;
        for(int i=1;i<=n;i++)
        {
            people.insert(i);
        }

        int id=0;
        while(!people.empty())
        {
            id=(id+k)%people.size();
            auto it=people.find_by_order(id);
            cout<<*it<<" ";
            people.erase(it);
        }
        
        // for(ll i=0;i<n;i++)
        // {
        //     cout<<result[i]<<" ";
        // }
       
    }
    return 0;
}