#include<bits/stdc++.h>
using namespace std;
class DSU{
public:
    vector<int>rank,parent;
    int components;
    DSU(int n){
        rank.resize(n);
        parent.resize(n);
        components=n;
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int x)
    {
        if(x!=parent[x])
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
            parent[py]=px;
            
        }
        else if(rank[px]>rank[py])
        {
            parent[px]=py;
            
        }
        else{
            parent[py]=px;
            rank[px]++;
        }
        components--;
        return true;
    }


};

pair<int,int> maxCity(vector<pair<int,int>> edges, vector<int> scores){
    int n=scores.size();
    DSU dsu1(n),dsu2(n);
    //do the unite operation on the basis of odd scores and even score
    for(int i=0;i<n-1;i++)
    {
        int u=edges[i].first;
        int v=edges[i].second;
        if(scores[u]%2== 0 && scores[v]%2==0)
        {
            // cout<<"united: "<<u<<" "<<v <<" "<<scores[u]<<" "<<scores[v]<<endl;
            dsu1.unite(u,v);
        }
        else if(scores[u]%2!=0 && scores[v]%2!=0)
        {
            // cout<<"united: "<<u<<" "<<v <<" "<<scores[u]<<" "<<scores[v]<<endl;
            dsu2.unite(u,v);
        }
        
    }
    
    
    vector<int>odd_parent(n,0),even_parent(n,0);
    for(int i=0;i<n;i++)
    {
        odd_parent[dsu2.find(i)]++;
        even_parent[dsu1.find(i)]++;
    }
    int max_odd=*max_element(odd_parent.begin(),odd_parent.end());
    int max_even=*max_element(even_parent.begin(),even_parent.end());
    
    // cout<<n-dsu1.components<<" "<<n-dsu2.components<<endl;
    return {max_odd ,max_even};

}
int main(){
 
    int n;
    cin>>n;
    vector<int>scores(n);
    for(int i=0;i<n;i++){
        cin>>scores[i];
    }
    vector<pair<int,int>>edges(n-1);
    for(int i=0;i<n-1;i++){
        
        int a,b;
        cin>>a>>b;
        edges[i]={a-1,b-1};
        // cout<<"edges: "<<edges[i].first<<" "<<edges[i].second<<endl;
    }
    pair<int,int> ans=maxCity(edges,scores);
    cout<<ans.first<<" "<<ans.second<<endl;
    
    

    return 0;
}