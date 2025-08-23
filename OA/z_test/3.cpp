#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string &s,int i,int j)
{
    // int i=0;
    // int j=s.size()-1;
    while(i<j)
    {
        if(s[i]!=s[j])return false;
        i++;
        j--;
    }
    return true;
}

long long findDifferentString(string &s,unordered_set<string>&st,int i,int j)
{
    
    int n=s.size();
    if(i>=n || j<0)return 0;
    long long take=0,skip=0;
    if(isPalindrome(s,i,j))
    {
        if(!st.count(s.substr(i,j-i+1)))
        {
            st.insert(s.substr(i,j-i+1));
        }
        take=1+findDifferentString(s,st,i+1,j-1);
    }
    skip=max(findDifferentString(s,st,i+1,j),findDifferentString(s,st,i,j-1));
    return max(skip,take);
    
}

int main()
{
    string s;
    cin>>s;
    unordered_set<string>st;
    findDifferentString(s,st,0,s.size()-1);
    cout<<st.size()<<endl;
    return 0;

}