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
       vector<int> a(n);
         for(int i=0;i<n;i++)
         {
              cin>>a[i];
         }
         int maxE=*max_element(a.begin(),a.end());
         vector<int> b;
         vector<int> c;
         for(int i=0;i<n;i++)
         {
            if(a[i]!=maxE)
            {
                b.push_back(a[i]);
            }
            else
            {
                c.push_back(a[i]);
            }
         }
        if(b.size()==0)
        {
            cout<<-1<<endl;
        }
        else
         {cout<<b.size()<<" "<<c.size()<<endl;
            for(int i=0;i<b.size();i++)
            {
                cout<<b[i]<<" ";
            }
            cout<<endl;
            for(int i=0;i<c.size();i++)
            {
                cout<<c[i]<<" ";
            }
            cout<<endl;}
    }
    return 0;
}