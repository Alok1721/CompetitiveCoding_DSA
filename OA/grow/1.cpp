#include<bits/stdc++.h>
using namespace std;
class DSU{

    public:
        vector<int>parent;
        vector<int>rank;

        DSU(int n)
        {
            parent.resize(n);
            rank.resize(n);
            iota(parent.begin(),parent.end(),0);
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
            if(rank[px]<rank[py])
            {
                parent[px]=py;
            }
            else if(rank[px]>rank[py])
            {
                parent[py]=px;
            }
            else
            {
                parent[py]=px;
                rank[px]++;
            }
            return true;
        }

};
vector<pair<int,int>>dirs={{1,0},{-1,0},{0,1},{0,-1}};

bool isValid(int i,int j,vector<vector<int>>&mat)
{
    int m=mat.size();
    int n=mat[0].size();
    return (i>=0 && j>=0 && i<m && j<n && mat[i][j]!=0);
}
void dfs(int i,int j,vector<vector<int>>&mat,DSU &dsu)
{
    int m = mat.size(), n = mat[0].size();
    int id = i*n + j;
    // dsu.unite(i,i*mat[0].size()+j);
    mat[i][j]=0;
    for(auto d:dirs)
    {
        int ni=i+d.first;
        int nj=j+ d.second;
        if(isValid(ni,nj,mat))
        {
            int nid = ni*n + nj;
            if (dsu.unite(id, nid)) {
                dfs(ni,nj,mat,dsu);
            }
        }
    }
}

int maxScore(vector<vector<int>>& mat, int m, int n) {
 
    vector<vector<int>>original=mat;
    DSU dsu(m*n);
    // visited[]
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(mat[i][j]==1)
            {
                dfs(i,j,mat,dsu);
            }
        }
    }
    unordered_map<int,int >clusterCount;//<parent,<all index>>

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(original[i][j]==1)
            {int p=dsu.find(i*n+j);
            clusterCount[p]++;}
        }
    }
    vector<int>clusters;
    for(auto it:clusterCount)
    {
        clusters.push_back(it.second);
    }

    sort(clusters.rbegin(),clusters.rend());
    cout<<"cluster size:"<<clusters.size()<<endl;
    int ans=0;
    for(int i=0;i<clusters.size();i+=2)
    {
        ans+=clusters[i];
    }
    return ans;

}
int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>>mat(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }

    cout<<maxScore(mat,m,n);
 
    return 0;
}