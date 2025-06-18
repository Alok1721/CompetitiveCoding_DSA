#include <bits/stdc++.h>
using namespace std;



int main()
{
    long long t;
    cin>> t;
    while(t--)
    {
        long long n,p;
        cin >> n >> p;
        vector<long long> a(n);
        for(long long i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<long long> b(n);
        for(long long i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        vector<pair<long long, long long>> v;
        for(long long i = 0; i < n; i++)
        {
            v.push_back({b[i], a[i]});
        }

        //sort by b[i]
        sort(v.begin(), v.end());
        //break when b[i] > p
        long long min_cost = p;
        long long alreadyAnnounced = 1;
        for(long long i = 0; i < n; i++)
        {
            if(v[i].first>=p)
                break;

            if(alreadyAnnounced+v[i].second>n)
            {
                min_cost+= v[i].first*(n-alreadyAnnounced);
                alreadyAnnounced = n;
                break;
            }
            else
            {
                min_cost += v[i].first * v[i].second;
                alreadyAnnounced += v[i].second;
            }
        }
        min_cost += (n - alreadyAnnounced) * p; // Add remaining cost if any
        //calcullate min_cost
        cout << min_cost << endl;

       
    }
    return 0;
}