#include <bits/stdc++.h>
using namespace std;

long long findMaxX(vector<vector<int>>&matrix)
{
    int m=matrix.size();
    int n=matrix[0].size();
    long long total=0;
    //step1: check for negative count( if even ans=total, else total-2*least),least
    int least=INT_MAX;
    int count=0;

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(matrix[i][j]<0)count++;
            least=min(least,abs(matrix[i][j]));
            total+=abs(matrix[i][j]);
        }
    }
    if(count%2==0)
    {
        return total;
    }
    else
    {
        return total-2*least;
    }

    

}


int main()
{
    long long t;
    cin>> t;
    while(t--)
    {
       int m,n;
       cin>>m>>n;
       vector<vector<int>>matrix(m,vector<int>(n));

       for(int i=0;i<m;i++)
       {
        for(int j=0;j<n;j++)
        {
            cin>>matrix[i][j];
        }
       }

       cout<<findMaxX(matrix)<<endl;

    }
    return 0;
}