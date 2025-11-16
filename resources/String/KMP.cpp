#include<bits/stdc++.h>
using namespace std;
vector<int>findLPS(string &s)
{
    int n=s.size();
    vector<int>lps(n,0);
    int i=1;
    int len=0;
    while(i<n)
    {
        if(s[i]==s[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len>0)
            {
                len=lps[len-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}
bool checkPattern(string &s,string &pattern)
{
    int n=s.size();
    int m=pattern.size();
    vector<int>lps=findLPS(pattern);
    cout<<"lps:"<<endl;
    for(auto it:lps)cout<<it<<" ";
    int i=0,j=0;
    while(i<n)
    {
        if(s[i]==pattern[j])
        {
            i++;j++;
            if(j==m)return true;
        }
        else
        {
            if(j>0)
            {
                j=lps[j-1];
            }
            else
            {
                i++;
            }
        }
    }
    return false;
}


int main()
{
    string s,pattern;
    cin>>s>>pattern;
    cout<<checkPattern(s,pattern)<<endl;
    return 0;

}