#include <bits/stdc++.h>
using namespace std;



int main()
{
    long long t;
    cin>> t;
    while(t--)
    {
       int n;
       cin>>n;
       string s;
       cin>>s;
       unordered_map<int,int> freq;
       int count=0;
       int total_sum=0;
       
       for(int i=0;i<n;i++)
       {
        freq[s[i]]++;
        if(freq[s[i]]==1) {
            count++;
            
        }
        total_sum+=count;
        
       }
       cout<<total_sum<<endl;
    }
    return 0;
}