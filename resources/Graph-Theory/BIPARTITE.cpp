bool checkBipartite(int node,unordered_map<int,vector<int>>&graph,vector<int>&team,int color)
{
    team[node]=color;
    for(auto nei:graph[node])
    {
        if(team[nei]==-1)
        {
            if(!checkBipartite(nei,graph,team,1-color))
            {
                return false;
            }
        }
        else if(team[nei]==color)
        {
            return false;
        }
    }
    return true;

}