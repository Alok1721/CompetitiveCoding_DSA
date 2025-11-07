#include<bits/stdc++.h>
using namespace std;

unordered_map<string,int>position;
unordered_map<int,vector<int>>graph;
int result=0;
void dfs(int node,unordered_set<int>&visited,int currL,string currS,vector<string>&nums)
{
    visited.insert(node);
    currL+=nums[node].length();
    currS+=nums[node];
    if(currS.back()==currS.front())
    {
        result=max(result,currL);
    }
    for(auto neighbor:graph[node])
    {
        if(!visited.count(neighbor))
        {
            dfs(neighbor,visited,currL,currS,nums);
        }
    }
    visited.erase(node);
}
int findLongestString(vector<string>&nums)
{
    int n=nums.size();
    
    for(int i=0;i<n;i++)
    {
        string curr=nums[i];
        for(int j=i+1;j<n;j++)
        {
            string next=nums[j];
            if(curr.back()==next.front())
            {
                graph[i].push_back(j);
            }
        }
    }
    unordered_set<int>visited;
    for(int i=0;i<n;i++)
    {
        if(!visited.count(i))
        {
            int currL=0;
            string currS="";
            dfs(i,visited,currL,currS,nums);
        }
    }
    return result;
}



int main()
{
    int n;
    cin>>n;
    vector<string> strings(n);
    for(int i=0;i<n;i++)
    {
        cin>>strings[i];
    }
    cout<<findLongestString(strings)<<endl;
    return 0;
}