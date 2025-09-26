#include<bits/stdc++.h>
using namespace std;

int findMaxMod(string &s)
{
    int result=0;
    for(int i=1;i<s.length();i++)
    {
        int left=stoi(s.substr(0,i));
        int right=stoi(s.substr(i));
        int temp=(left%7)*(right%7);
        result=max(result,temp);
    }
    return result;

}


int main()
{
    string s;
    cin>>s;
    cout<<findMaxMod(s);//result=(a%7 * b%7) where a+b=s;
    
    return 0;
}