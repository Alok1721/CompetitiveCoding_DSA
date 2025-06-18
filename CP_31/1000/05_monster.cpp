#include <bits/stdc++.h>
using namespace std;



int main()
{
    long long t;
    cin>> t;
    while(t--)
    {
       long long n,k;
       cin >> n >> k;

         vector<pair<long long,long long>> a(n);
         for(long long i = 0; i < n; i++)
         {
            long long temp;
            cin >> temp;
            a[i] = {i,temp%k==0?k:temp%k};

         }
         sort(a.begin(), a.end(), [](pair<long long,long long> &a, pair<long long,long long> &b) {
            if(a.second != b.second)
                return a.second > b.second;
            return a.first< b.first;
         });
        
            for(long long i = 0; i < n; i++)
            {
                cout << a[i].first + 1 << " ";
            }
            cout << endl;


    }
    return 0;
}