#include<bits/stdc++.h>
using namespace std;
int solve(string &s1,string &s2,int i,int j)
{
    if(i>=s1.size() || j<0 )return 0;
    int take=0,skip=0;
    if(s1[i]==s2[j])
    {
        take=1+solve(s1,s2,i+1,j-1);
    }
    skip=max(solve(s1,s2,i+1,j),solve(s1,s2,i,j-1));
    return max(take,skip);
}

int findLongestPalindrome(string &s1,string &s2)
{
    int n1=s1.size();
    int n2=s2.size();
    return solve(s1,s2,0,n2-1);
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    cout<<findLongestPalindrome(s1,s2)<<endl;
    return 0;
}