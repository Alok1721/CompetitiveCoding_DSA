#include <bits/stdc++.h>
using namespace std;



int main()
{
    int t;
    cin>> t;
    while(t--)
    {int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<int> prefix_sum(n+1, 0);
        for(int i = 1; i <= n; i++)
        {
            prefix_sum[i] = prefix_sum[i - 1] + a[i - 1];
        }
        
        while(q--)
        {
            int total = prefix_sum[n]; // Total sum of the array
            
            int l, r,k;
            cin >> l >> r>>k;
           
            total -=prefix_sum[r] - prefix_sum[l - 1]; // Subtract the sum of the range [l, r]
            total += k*(r-l+1); // Add the value k
            if(total%2!= 0)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
       
    }
    return 0;
}