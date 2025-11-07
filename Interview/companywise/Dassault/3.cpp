#include<bits/stdc++.h>
using namespace std;
string reshapeString(string s,int k)
{
    int n=s.length();
    if(k<=0 || k>n)return s;
    string result="";
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]==' ')
        {
            continue;
        }
        result+=s[i];
        count++;
        if(count==k){
            result+='\n';
            count=0;
        }
    }
    return result;
}
int main()
{
    string s;
    cin>>s;
    int k;
    cin>>k;
    cout<<reshapeString(s,k);
    return 0;
}