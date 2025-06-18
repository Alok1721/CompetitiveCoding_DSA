#include <bits/stdc++.h>
using namespace std;



int main()
{
    long long t;
    cin>> t;
    while(t--)
    {
        long long n;
        cin >> n;
        long long first_mins=LLONG_MAX;
        vector<long long> second_mins;
        long long result = 0;
        for(long long i = 0; i < n; i++)
        {
            long long m;
            cin >> m;
            vector<long long> a(m);
            for(long long j = 0; j < m; j++)
            {
                cin >> a[j];
            }
            sort(a.begin(), a.end());
            first_mins = min(first_mins, a[0]);
            if(m>1)
            {
                second_mins.push_back(a[1]);
            }
        }
        sort(second_mins.begin(), second_mins.end());
        result = accumulate(second_mins.begin(), second_mins.end(), 0LL);
        result-=*min_element(second_mins.begin(), second_mins.end());
        result += first_mins;
        cout<< result << endl;
    }
    return 0;
}