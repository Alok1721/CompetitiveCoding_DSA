#include<bits/stdc++.h>
using namespace std;
class DSU{
    public:
    vector<int>parent,rank;
    int components;

    DSU(int n)
    {
        parent.resize(n+1);
        rank.resize(n+1);
        iota(parent.begin(),parent.end(),0);
        components=n;
    }
    int find(int x)
    {
        if(parent[x]!=x)
        {
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x,int y)
    {
        int px=find(x);
        int py=find(y);
        if(px==py)
        {
            return false;
        }
        if(rank[px]<rank[py])
        {
            parent[px]=py;
        }
        else if(rank[px]>rank[py])
        {
            parent[py]=px;
        }
        else{
            parent[py]=px;
            rank[py]++;
        }
        components--;
        return true;
    }
};

int winningScore(vector<int>students,vector<pair<int,int>>pairs)
{
    DSU dsu(students.size());
    for(auto it:pairs)
    {
        dsu.unite(it.first,it.second);
    }

    int maxScore=0;
    unordered_map<int,vector<int>>mp;//parent ->children
    for(int i=0;i<students.size();i++)
    {
        mp[dsu.find(i)].push_back(i);
    }
    for(auto it:mp)
    {
        int parent=it.first;
        cout<<"parent: "<<parent<<endl;
        vector<int>children=it.second;
        int sum=0;
        for(int i=0;i<children.size();i++)
        {
            sum+=students[children[i]];
            cout<<children[i]<<" ";
        }
        cout<<endl;
        maxScore=max(maxScore,sum);
    } 
    return maxScore;   
}

int main()
{
    int n;
    cin>>n;
    vector<int>students(n);
    for(int i=0;i<n;i++)
    {
        cin>>students[i];
    }
    int m,c;
    cin>>m>>c;
    vector<pair<int,int>>pairs(m);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        pairs.push_back({a-1,b-1});
    }
    cout<<winningScore(students,pairs)<<endl;
    
    return 0;
}