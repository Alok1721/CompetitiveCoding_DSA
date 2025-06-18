#include <bits/stdc++.h>
using namespace std;

int findSwap(string s, int n)
{
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }
    string temp="";
    // cout<<"freq['0'] = "<<freq['0']<<endl;
    // cout<<"freq['1'] = "<<freq['1']<<endl;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            if(freq['1']>0)
            {
                temp+='1';
                freq['1']--;
            }
            else{
                break;
            }
              
           
        }  else if(s[i]=='1')
        {
            if(freq['0']>0)
            {
                temp+='0';
                freq['0']--;
            }
            else{
                break;
            }
        }
        

    }

    // cout<<"temp = "<<temp<<endl;
    // cout<<"freq['0'] = "<<freq['0']<<endl;
    // cout<<"freq['1'] = "<<freq['1']<<endl;
    // cout<<"temp.size() = "<<temp.size()<<endl;
    return n-temp.size();
}


int main()
{
    int t;
    cin>> t;
    while(t--)
    {
        string s;
        cin>>s;
        int n=s.size();
        cout<<findSwap(s, n) << endl;
    }
    return 0;
}