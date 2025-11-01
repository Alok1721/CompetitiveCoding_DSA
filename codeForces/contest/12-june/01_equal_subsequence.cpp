#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n,x;
        cin>>n>>x;

        string result="";
        for(int i=0;i<x;i++)
        {
            result+='1';
        }
        int remain=n-(int)result.size();
        for(int i=0;i<remain;i++)
        {
            result+='0';
        }
        cout<<result<<endl;
    }
    
    return 0;
}