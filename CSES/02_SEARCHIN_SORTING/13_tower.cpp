#include <bits/stdc++.h>
#define mod ((int)1e9+7)
using namespace std;

int findMinTower(vector<long long > &cubes)
{
    multiset<long long> towers;
    for(long long cube:cubes)
    {
        auto it=towers.upper_bound(cube);
        if(it!=towers.end())
        {
            towers.erase(it);
        }
        towers.insert(cube);
    }

    return towers.size();
}


int main()
{
    int t;
    t=1;
    while(t--)
    {
        long long n;
        cin>>n;
        vector<long long> cubes(n);
        for(long long i=0;i<n;i++)
        {
            cin>>cubes[i];
        }

        cout<<findMinTower(cubes)<<endl;
       
    }
    return 0;
}