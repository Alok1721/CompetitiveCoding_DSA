#include <bits/stdc++.h>
using namespace std;



int main()
{
    int t;
    cin>> t;
    while(t--)
    {
       int n;
       n=3;
       vector<int> a(n);
       
       for(int i=0;i<n;i++)
       {
        cin>>a[i];
       }
       if(a[2]%2==1)
       {
        if(a[1]>a[0])cout<<"Second"<<endl;
        else cout<<"First"<<endl;
       }else{
        if(a[0]>a[1]) cout<<"First"<<endl;
        else cout<<"Second"<<endl;
       }
    }
    return 0;
}