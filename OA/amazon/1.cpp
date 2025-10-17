#include<bits/stdc++.h>
using namespace std;
int findMaxServer(vector<int> &a)
{
    int n=a.size();
   int max1=1;
   for(int i=1;i<n;i++)
   {
        if(a[i]>a[i-1])
        {
            max1++;
        }else if(a[i]==a[i-1])
        {
            continue;
        }
        else 
        {
            max1=1;
        }
   }
   int max2=1;
   for(int i=1;i<n;i++)
   {
        if(a[i]<a[i-1])
        {
            max2++;
        }else if(a[i]==a[i-1])
        {
            continue;
        }
        else 
        {
            max2=1;
        }
   }
   int result=max(max1,max2);

    return result;
}
int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }  
    cout<<findMaxServer(a);
    return 0;
}