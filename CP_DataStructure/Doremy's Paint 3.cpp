#include <bits/stdc++.h>
using namespace std;



int main()
{
    int t;
    cin>> t;
    while(t--)
    {
        int n;
        cin>> n;
        map<int,int> mp;
        vector<int> a(n);
        for(int i=0; i<n; i++)
            cin>> a[i];
        
        for(int i=0; i<n; i++)
        {
            mp[a[i]]++;
        }
        if(mp.size()>=3)
        {
            cout<< "NO" << endl;
        }
        else if(mp.size()==2)
        {
            auto it=mp.begin();
            int x=it->second;
            it++;
            int y=it->second;
            if(x==y)
            {
                cout<< "YES" << endl;
            }
            else if(abs(x-y)==1)
            {
                cout<< "YES" << endl;
            }
            else
            {
                cout<< "NO" << endl;
            }
            
        }
        else{
            cout<< "YES" << endl;
        }
       
    }
    return 0;
}