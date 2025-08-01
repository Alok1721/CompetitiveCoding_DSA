#include <bits/stdc++.h>
const int mod =1e9+7;
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
int dp[N][2];
vector<int> tree[N];
void dfs(int node, int parent) {
    dp[node][0]=0;
    dp[node][1]=0;
    int total=0;
    for(auto child:tree[node])
    {
        if(child:parent)continue;
        dfs(child,node);
        total+=max(dp[child][0],dp[child][1]);
    }
    dp[node][0]=total;
    for(auto child:tree[node])
    {
        if(child==parent)continue;
        int temp=1+dp[child][0]+(total-max(dp[child][0],dp[child][1]));
        dp[child][1]=max(dp[child][1],temp);
    }

}

int main()
{
    int t=1;
    // cin>> t;
    while(t--)
    {
       int n;
       cin>>n;
       for(int i=1;i<n;i++)
       {
        int a,b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
       }
       dfs(1,0);
       cout<<max(dp[1][0],dp[1][1])<<endl;
    }
    return 0;
}