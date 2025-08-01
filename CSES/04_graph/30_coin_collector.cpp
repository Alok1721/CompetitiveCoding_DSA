#include<bits/stdc++.h>
using namespace std;


const int N = 1e5 + 7;
vector<int>graph[N],reverse_graph[N];
vector<int>order,component;
vector<vector<int>>sccs;
bool visited[N];
int scc_id[N];
long long coins[N],scc_coins[N];
vector<int>dag[N];
long long dp[N];

//step1:first dfs to stor the finish time order
//similar to topological sort
void dfs(int node) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
    order.push_back(node);
}


//step2:this dfs on reverse graph to find sccs
//mark each node with its scc id and collect coins in each scc id
void dfs2(int node,int id)
{
    visited[node]=true;
    scc_id[node] = id;
    scc_coins[id]+=coins[node];// accumulate coins in the current SCC
    for(int nei:reverse_graph[node])
    {
        if(!visited[nei])
        {
            dfs2(nei,id);
        }
    }
}

//step3: dp on dag
//this is to find the maximum coins we can collect in each scc
long long dfs_dp(int u)
{
    if(dp[u]!=-1)return dp[u];
    dp[u]=scc_coins[u];
    for(int v:dag[u])
    {
        dp[u]=max(dp[u],scc_coins[u]+dfs_dp(v));
    }
    return dp[u];
}

//main function
int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>coins[i]; // input coins for each node
    }

    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        reverse_graph[b].push_back(a);

    }

    //use kosaraju algo
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            dfs(i);
        }
    }

    fill(visited, visited + n + 1, false); // reset visited for second DFS
    int scc_count = 0;
    for(int i=n-1;i>=0;i--)
    {
        int node = order[i];
        if(!visited[node])
        {
            scc_coins[scc_count] = 0; // reset coins for new SCC
            dfs2(node,scc_count);
            scc_count++;
        }
    }

    // Build the DAG of SCCs
    for(int i=1;i<=n;i++)
    {
        for(int nei:graph[i])
        {
            if(scc_id[i] != scc_id[nei]) // only add edges between different SCCs
            {
                dag[scc_id[i]].push_back(scc_id[nei]);
            }
        }
    }

    // Initialize dp array
    fill(dp, dp + scc_count, -1);
    long long max_coins = 0;
    for(int i=0;i<scc_count;i++)
    {
        max_coins = max(max_coins, dfs_dp(i));
    }
    cout << max_coins << endl; // Output the maximum coins collected
    return 0;

}