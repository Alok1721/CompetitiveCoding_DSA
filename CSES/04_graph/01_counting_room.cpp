#include <bits/stdc++.h>
#define mod ((int)1e9+7)
using namespace std;

vector<pair<int,int>> dirs={{1,0},{0,1},{-1,0},{0,-1}};
void dfs(vector<vector<char>> &a,int i,int j)
{
    if(i<0 || i>=(int)a.size() ||j>(int)a[0].size()|| j<0 ||a[i][j]!='.')return ;
    a[i][j]='#';

    for(auto dir:dirs)
    {
        int x=i+dir.first;
        int y=j+dir.second;
    
            dfs(a,x,y);
       
    }
}

int main()
{
    int n,m;
    cin>> n>>m;
    if(n<=0 || m<=0){
        cout<<0<<endl;
        return 0;
    }
    vector<vector<char>>a(n,vector<char>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    //counting rooms
    int count_room=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]=='.')
            {
                count_room++;
                dfs(a,i,j);
            }
        }
    }
    cout<<count_room<<endl;
    return 0;
}