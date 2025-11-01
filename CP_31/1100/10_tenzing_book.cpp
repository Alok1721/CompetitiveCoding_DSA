#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(vector<int>&a,vector<int>&b,vector<int>&c,int x,int n)
{
    vector<vector<int>>prefix(3);
    int num=0;
    prefix[0].push_back(0);
    prefix[1].push_back(0);
    prefix[2].push_back(0);
    for(auto it:a )
    {
        
        if((num|it)!=num)
        {
            num|=it;
            prefix[0].push_back(num);
        }
    }
    num=0;
    for(auto it:b )
    {
        if((num|it)!=num)
        {
            num|=it;
            prefix[1].push_back(num);
        }
    }
    num=0;
    for(auto it:c )
    {
        if((num|it)!=num)
        {
            num|=it;
            prefix[2].push_back(num);
        }
    }
    
    for(auto it1:prefix[0])
    {

        for(auto it2:prefix[1])
        {
            for(auto it3:prefix[2])
            {
                if( (it1|it2|it3) == x)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
    
}


string canGetRating(int n, vector<int>& a, vector<int>& b, vector<int>& c, int x) {
    

    if(solve(a,b,c,x,n))
    {
        return "YES";
    }
    else {
        return "NO";
    }

}


int main()
{
    long long t;
    cin>> t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        vector<int> a(n),b(n),c(n);
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }
        for(int i=0;i<n;i++) {
            cin>>b[i];
        }
        for(int i=0;i<n;i++) {
            cin>>c[i];
        }
        cout<<canGetRating(n,a,b,c,x)<<endl;
    }
    return 0;
}