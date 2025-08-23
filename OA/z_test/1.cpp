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

string smallestPalindrome(string &s)
{
    string ns=s;
    reverse(ns.begin(),ns.end());
    ns.pop_back();
    ns=ns+s;
    string result=ns;
    for(int i=0;i<s.size();i++)
    {
        if(isPalindrome(ns,i,ns.size()-1))
        {
            result=ns.substr(i);
            // cout<<"check"<<endl;
        }
    }
    // if(isPalindrome(ns))return ns;
    return result;
}

int main()
{
    string s;
    cin>>s;
    cout<<smallestPalindrome(s)<<endl;

    return 0;
}