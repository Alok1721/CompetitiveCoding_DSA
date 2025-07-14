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
       vector<int>a(n);
       //create the set to check for distinct charcterr contain by set or not, if yes then ans=no other wise answer=yes
       unordered_set<int> st;
       for(int i=0;i<n;i++)
       {
        cin>>a[i];
        st.insert(a[i]);
       }

       if(st.size()<n)
       {
        cout<<"YES"<<endl;
       }else
       {
        cout<<"NO"<<endl;
       }

       
       
    }
    return 0;
}