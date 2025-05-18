#include <bits/stdc++.h>
using namespace std;

int countArrowCost(vector<vector<char>>& a)
{
    int cost = 0;
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(a[i][j] == 'X')
            {
                if(i<5 && j<5)
                {
                    cost+=min(i+1,j+1);
                }
                else if(i<5 && j>=5)
                {
                    cost+=min(i+1,10-j);
                }
                else if(i>=5 && j<5)
                {
                    cost+=min(10-i,j+1);
                }
                else
                {
                    cost+=min(10-i,10-j);
                }
            }
        }
    }
    return cost;
}

int main()
{
    int t;
    cin>> t;
    while(t--)
    {
        vector<vector<char>> a(10,vector<char>(10));

        for(int i=0; i<10; i++)
            for(int j=0; j<10; j++)
                cin>> a[i][j];

        cout<<countArrowCost(a)<<endl;
        
    }
    return 0;
}