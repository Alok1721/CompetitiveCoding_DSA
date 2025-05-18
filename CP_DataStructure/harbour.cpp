#include <bits/stdc++.h>
using namespace std;

int findFuel(int n, vector<int> &a, int x) {
    vector<int> route;
    route.push_back(0);
    for(int i=0; i<n; i++)
    {
        route.push_back(a[i]);
    }
    int ans = 0;
    for(int i=0;i<route.size()-1;i++)
    {
        ans= max(ans, abs(route[i+1] - route[i]));
    }
    int temp=2*(abs(route.back()-x));
    
    ans = max(ans, temp);
    return ans;
}

int main()
{
    int t;
    cin>> t;
    while(t--)
    {
        int n,x;
        cin>> n;
        cin>> x;
        vector<int> a(n);
        for(int i=0; i<n; i++)
            cin>> a[i];
        
        cout<<findFuel(n,a,x)<<endl;
    }
    return 0;
}