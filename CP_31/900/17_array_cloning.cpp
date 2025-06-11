#include <bits/stdc++.h>
using namespace std;



int main()
{
    int t;
    cin>> t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<long long>a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        unordered_map<long long,long long> mp;
        for(auto it:a)
        {
            mp[it]++;
        }

        //find the max frequency
        long long maxFreq=0;
        for(auto it:mp)
        {
            maxFreq=max(maxFreq,it.second);
        }

        //find the operatioin for swapping and clone
        int operation=0;
        while(maxFreq<n)
        {
            operation++;//cloning
            if(2*maxFreq<=n)
            {
                operation+=maxFreq;
                maxFreq*=2;
            }
            else
            {
                operation+=n-maxFreq;
                maxFreq=n;
            }
        }
        cout<<operation<<endl;
       
    }
    return 0;
}