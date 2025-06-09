#include <bits/stdc++.h>
#define mod ((int)1e9+7)
using namespace std;



int main()
{
    long long n,x;
    cin>>n>>x;
    vector<int> weight(n);
    for(int i=0;i<n;i++)
    {
        cin>>weight[i];
    }
    long long i=0;
    long long j=n-1;
    long long ans=0;
    sort(weight.begin(),weight.end());
    while(i<=j)
    {
        if(weight[i]+weight[j]<=x)
        {
            ans++;
            i++;
            j--;
        }
        else if(weight[j]<=x)
        {
            ans++;
            j--;
        }

    }
    

    cout<<ans<<endl;

    return 0;
}