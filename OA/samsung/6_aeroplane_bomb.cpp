#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void dfs(int row,int col,int curr_coins,int rowSafe,bool isBombed,int &max_coins,vector<vector<int>>&arr)
{
    if(col<0 || col>=5 ||row<0)
    {
        max_coins=max(max_coins,curr_coins);
        return;
    }

    if(arr[row][col]==1)//present coin
    {
        int new_coins=curr_coins+1;
        if(isBombed)rowSafe--;
        dfs(row-1,col,new_coins,rowSafe,isBombed,max_coins,arr);//move up
        dfs(row-1,col-1,new_coins,rowSafe,isBombed,max_coins,arr);//move up-left
        dfs(row-1,col+1,new_coins,rowSafe,isBombed,max_coins,arr);//move up-right
    }
    else if(arr[row][col]==0)//no coin
    {
        if(isBombed)rowSafe--;
        dfs(row-1,col,curr_coins,rowSafe,isBombed,max_coins,arr);//move up
        dfs(row-1,col-1,curr_coins,rowSafe,isBombed,max_coins,arr);//move up-left
        dfs(row-1,col+1,curr_coins,rowSafe,isBombed,max_coins,arr);//move up-right
    }
    else if(arr[row][col]==2)//bomb
    {
        if(!isBombed){
            isBombed=true;
            rowSafe=4;
            dfs(row-1,col,curr_coins,rowSafe,isBombed,max_coins,arr);//move up
            dfs(row-1,col-1,curr_coins,rowSafe,isBombed,max_coins,arr);//move up-left
            dfs(row-1,col+1,curr_coins,rowSafe,isBombed,max_coins,arr);//move up-right
        }
        else if(isBombed && rowSafe>0)
        {
            rowSafe--;
            dfs(row-1,col,curr_coins,rowSafe,isBombed,max_coins,arr);//move up
            dfs(row-1,col-1,curr_coins,rowSafe,isBombed,max_coins,arr);//move up-left
            dfs(row-1,col+1,curr_coins,rowSafe,isBombed,max_coins,arr);//move up-right
        }
        else
        {
            max_coins=max(max_coins,curr_coins);
            return;
        }

    }
}

int main()
{   
    int n;
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(5,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<5;j++)
        {
            cin>>arr[i][j];
        }
    }
    int max_coins=0;
    //spaceship at center
    dfs(n-1,1,0,5,false,max_coins,arr);//move left
    dfs(n-1,2,0,5,false,max_coins,arr);//center
    dfs(n-1,3,0,5,false,max_coins,arr);//move right
    cout<<max_coins<<endl;

    return 0;
}