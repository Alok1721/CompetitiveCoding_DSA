#include <bits/stdc++.h>
#define mod ((int)1e9+7)
using namespace std;

long long findRounds(vector<int>coins)
{
    long long n= coins.size();
    multiset<int>st(coins.begin(),coins.end());
    long long target=1,rounds=0;

    while(target<=n)
    {
        bool found=false;
        for(int i=target;i<=n;i++)
        {
            auto it=st.find(i);
            if(it!=st.end())
            {
                st.erase(it);
                target++;
                found=true;
            }
        }
        if(!found)break;
        rounds++;

    }
    

    return rounds;

}


int main()
{
    int t=1;
    // cin>> t;
    while(t--)
    {
       
        long long n;
        cin>>n;
        vector<int> coins(n+1);
        for(long long i=0;i<n;i++)
        {
            cin>>coins[i];
        }

        cout<<findRounds(coins)<<endl;
    }
    return 0;
}