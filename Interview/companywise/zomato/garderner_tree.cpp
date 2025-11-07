#include <bits/stdc++.h>
#define mod ((int)1e9+7)
using namespace std;



int main()
{
    long long t;
    cin>> t;
    while(t--)
    {
       long long n,k;
         cin >> n >> k;//node, operations
         //handle edge case
         if (n == 1)
         {
            cout<<(k>=1?0:1)<<"\n";
            continue;
         }

         //step1:build graph + degree for leave tracking
         vector<vector<long long>>graph(n+1);//nodes 1 to n
            vector<long long>degree(n+1 , 0);

            for (long long i = 0; i < n - 1; i++) 
            {
                long long u, v;
                cin >> u >> v;
                graph[u].push_back(v);
                graph[v].push_back(u);
                degree[u]++;
                degree[v]++;
            }

        //step 2: Find the leaves
        queue<long long>q;
        for (long long i = 1; i <= n; i++) 
        {
            if (degree[i] == 1) 
            {
                q.push(i);
            }
        }


        //step 3: Remove leaves till k operations are done
        long long node_removed = 0;
        while (!q.empty() && k > 0) 
        {
            long long size = q.size();
            node_removed += size;
            k--;

            for (long long i = 0; i < size; i++) 
            {
                long long leaf = q.front();
                q.pop();

                for (long long neighbor : graph[leaf]) 
                {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1) 
                    {
                        q.push(neighbor);
                    }
                }
            }
        }
        //step 4: Calculate remaining nodes
        long long remaining_nodes = n - node_removed;
        cout << remaining_nodes << "\n";
    }

    return 0;
}