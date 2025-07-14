#include <bits/stdc++.h>
const int mod =1e9+7;
using namespace std;
typedef long long ll;

int minTime(vector<int>&a)
{
    int n=a.size();
    int total=0;

    for(int i=0;i<n;i++)
    {
        total+=a[i];
    }
    
    int maxE=*max_element(a.begin(),a.end());
    if(maxE<=total)return total+maxE;
    return 2*maxE;
}


int main()
{
    int t;
    t=1;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        cout<<minTime(a)<<endl;
    }
    return 0;
}