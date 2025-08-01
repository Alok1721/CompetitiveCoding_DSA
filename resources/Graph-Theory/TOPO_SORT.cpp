void topoSort(int node,unordered_map<int,vector<pair<int,int>>>&adj,vector<int>&vis,stack<int>&st)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            int v=it.first;
            if(!vis[v])
            {
                topoSort(v,adj,vis,st);
            }
        }
        st.push(node);
    }