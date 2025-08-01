#include <bits/stdc++.h>
const int mod =1e9+7;
using namespace std;
typedef long long ll;


vector<int> subordinates;
unordered_map<int, vector<int>> adj;
int dfs(int node)
{
    int count=0;
    for(int child:adj[node]) {
        count += dfs(child)+1;
    }
    subordinates[node] = count;
    return count;   
}


int main()
{
    int t=1;
    // cin>> t;
    while(t--)
    {
        int n;
        cin>>n;
        subordinates.resize(n+1, 0);
        for(int i = 2; i <= n; i++) {
            int boss;
            cin >> boss;
            adj[boss].push_back(i);
        }
        //finding the subordinate of each node
        dfs(1);
        //output the subordinates count
        for(int i=1; i<= n; i++) {
            cout << subordinates[i] << " ";
        }
        cout << endl;
       
    }
    return 0;
}