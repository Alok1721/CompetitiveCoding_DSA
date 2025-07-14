#include <bits/stdc++.h>
using namespace std;

int totalBracketsMove(string &s,int n)
{
    int start=0;
    int close=0;
    int move=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')
        {
            start++;
        }
        else
        {
            close++;
        }
        if(close>start)
        {
            move++;
            close--;
        }
    }
    return move;
}


int main()
{
    long long t;
    cin>> t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        cout<<totalBracketsMove(s,n)<<endl;
       
    }
    return 0;
}