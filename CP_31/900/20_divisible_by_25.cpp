#include <bits/stdc++.h>
using namespace std;

int min_operations(string &s,string &temp)
{
    int n=s.size()-1;
    int checker_index=temp.size()-1;
    int operation=0;
    for(int i=n;i>=0;i--)
    {   
        if(s[i]==temp[checker_index])
        {
            checker_index--;
            if(checker_index<0)break;
        }
        else
        {
            operation++;
        }

    }
    if(checker_index>=0)operation=INT_MAX;
    return operation;
}


int main()
{
    int t;
    cin>> t;
    while(t--)
    {
        string n;
        cin>>n;

        vector<string> possible_value={"00","25","50","75"};
        int ans=INT_MAX;
        for(auto it:possible_value)
        {
            ans=min(ans,min_operations(n,it));
        }
        cout<<ans<<endl;
       
    }
    return 0;
}