#include <bits/stdc++.h>
using namespace std;

string canForm(string &s, string &t)
{
    int n=s.size();
    unordered_map<char,int> freq;
    for(auto it:t)
    {
    freq[it]++;
    }
    string result="";
    for(int i=n-1;i>=0;i--)
    {
        if(freq[s[i]]>0)
        {
            freq[s[i]]--;
            result+=s[i];
        }
    }
    reverse(result.begin(),result.end());
    return result==t?"YES":"NO";

}


int main()
{
    int t;
    cin>> t;
    while(t--)
    {
       string s,t;
       cin>>s>>t;

       cout<<canForm(s,t)<<endl;
    }
    return 0;
}