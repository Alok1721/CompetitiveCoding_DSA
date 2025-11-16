/* **Q5) RoundTrip:Visit everyCity Once**
``we have to take benefit of n-1 edges , it means connected graph(but still handle by external with for loop)  as donot visit the longest route path from starting node as (2*sum-longest path sum). ``
``` Learning:
1) finding the longest path weight nodes chain 
2) ways to visit all city atleast once.
 ```

```
 */

#include<bits/stdc++.h>
using namespace std;
int maxV,totalSum;
void dfs(int node, unordered_map<int, vector<pair<int, int>>> &graph, vector<bool> &visited,int currSum,int &lastNode)
{
    visited[node]=true;
    if(currSum>maxV)
    {
        maxV=currSum;
        lastNode=node;
    }
    for(auto &neighbor: graph[node])
    {
        int adjNode=neighbor.first;
        int weight=neighbor.second;
        if(!visited[adjNode])
        {
            totalSum+=weight;
            dfs(adjNode, graph, visited,currSum+weight,lastNode);
        }
    }
}


void minCostTrip(unordered_map<int, vector<pair<int, int>>> &graph,int n)
{
    vector<bool> visited(n , false);
    int lastNode=0;
    dfs(0, graph, visited,0,lastNode);

    fill(visited.begin(), visited.end(), false);
    maxV=0;
    totalSum=0;
    dfs(lastNode, graph, visited,0,lastNode);
}



int main()
{
    int n;
    cin >> n;
    maxV=totalSum=0;
    unordered_map<int, vector<pair<int, int>>> graph;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u-1].push_back({v-1, w});
        graph[v-1].push_back({u-1, w});
    }

    minCostTrip(graph,n);
    cout<<2*totalSum-maxV<<endl;
    return 0;
}
```