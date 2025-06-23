#include <bits/stdc++.h>
#define mod ((int)1e9+7)
using namespace std;



int main()
{
    int n;
    cin >> n;
    vector<int> sticks(n);
    for(int i=0;i<n;i++)
    {
        cin >> sticks[i];
    }

    sort(sticks.begin(), sticks.end());
    long long total_cost = 0;
    int median_index = (n-1) / 2;
    int median_length = sticks[median_index];
    for(int i = 0; i < n; i++)
    {
        total_cost += abs(sticks[i] - median_length);
    }
    cout << total_cost << endl;

    
    return 0;
}