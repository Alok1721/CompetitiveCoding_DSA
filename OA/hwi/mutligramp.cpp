#include<bits/stdc++.h>

using namespace std;

bool isValidAnagram(string &a,string &b)
{
    if(a.size()!=b.size())return false;
    unordered_map<char,int>freqS,freqSub;
    for(char ch:a)freqS[ch]++;
    for(char ch:b)freqSub[ch]++;
    return freqS==freqSub;
}

bool isValidMultigram(string &s,string &sub)
{
    int n=s.size();
    int m=sub.size();
    if(n%m!=0)return false;

    for(int i=0;i<n;i+=m)
    {
        string new_sub=s.substr(i,m);
        if(!isValidAnagram(new_sub,sub))
        {
            return false;
        }
    }
    return true;
}

string findSmallestAnagram(string &s)
{
    int n=s.size();
    for(int i=1;i<n;i++)
    {
        string sub=s.substr(0,i);
        int sub_size=sub.size();
        if(isValidMultigram(s,sub))
        {
            return sub;
        }
    }
    return "-1";
}

int main()
{
    string s;
    cin>>s;
    string result=findSmallestAnagram(s);
    cout<<result<<endl;
    return 0;
}