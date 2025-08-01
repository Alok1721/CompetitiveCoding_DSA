#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isFound(vector<ll>& height, ll max_height, ll waterUnit) {
    ll count = 0;
    for (int i = 0; i < height.size(); i++) {
        
        if (height[i] < max_height) {
            count += max_height - height[i];
        }
        if (count > waterUnit) {
            return false; // More water needed than available
        }
    }
    return count <= waterUnit; // Check if we can fill to max_height
}

int main()
{
    long long t;
    cin>> t;
    while(t--)
    {
        ll n,x;
        cin >> n >> x;
        vector<ll> height(n);
        for(int i = 0; i < n; i++)
        {
            cin >> height[i];
        }
        ll maxE = 1e12;
        ll minE=1;
        ll result = -1;
        while(minE <= maxE)
        {
            ll mid = (minE + maxE) / 2;
        
            if(isFound(height,mid,x))
            {
                result=mid;
                minE = mid + 1; // try for a larger value

            }
            else
            {
                maxE=mid-1;
            }
        }
        cout<<result<<endl;
        

    }
    return 0;
}