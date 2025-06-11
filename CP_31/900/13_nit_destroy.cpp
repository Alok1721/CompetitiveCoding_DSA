#include <bits/stdc++.h>
using namespace std;



int main()
{
    int t;
    cin>> t;
    while(t--)
    {
       int n;
       cin >> n;
       vector<int> a(n);
         for(int i = 0; i < n; i++)
         {
              cin >> a[i];
         }
         int zero_count = 0;
            for(int i = 0; i < n; i++)
            {
                if(a[i] == 0)
                {
                    zero_count++;
                }
            }
            if(zero_count == n) {cout <<0<<endl; continue;}
        
        int left = 0, right = n - 1;
        while(left < n && a[left]==0 ) left++;
        while(right >= 0 && a[right]==0 ) right--;
        bool flag = false;
        for(int i = left; i <= right; i++)
        {
            if(a[i] == 0)
            {
                flag = true;
            }
        }
        if(flag)
        {
            cout << 2 << endl;
            
        }else{
            cout << 1 << endl;
        }
        
    }
    return 0;
}