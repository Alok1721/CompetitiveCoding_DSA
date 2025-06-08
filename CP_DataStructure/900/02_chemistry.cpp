#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        long long n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<int> mp(26,0);
        for(int i=0;i<n;i++)
        {
            mp[s[i]-'a']++;
        }
        long long odd_freq=0;
        for(int i=0;i<26;i++)
        {
            odd_freq+=mp[i]%2;
        }

        if(odd_freq>k+1)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<enl;
        }
    }
    return 0;
}