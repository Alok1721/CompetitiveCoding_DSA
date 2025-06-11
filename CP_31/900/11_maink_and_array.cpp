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
         int minE=*min_element(a.begin(), a.end());
         int maxE=*max_element(a.begin(), a.end());
         cout<<maxE-minE<<endl;
    }
    return 0;
}