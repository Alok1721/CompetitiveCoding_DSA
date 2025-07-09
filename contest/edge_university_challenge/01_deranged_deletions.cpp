#include <bits/stdc++.h>
using namespace std;

vector<int>findDeranged(vector<int>&a)
{
    int n=a.size();

    vector<int>result;
    vector<int> temp=a;
    sort(temp.begin(), temp.end());
    for(int i=0;i<n;i++)
    {
        if(temp[i]!=a[i])
        {
            result.push_back(a[i]);
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        vector<int> result;
        result=findDeranged(a);

        if(result.empty())
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
            cout<<result.size()<<endl;
            for(auto it:result)
            {
                cout<<it<<" ";
            }
            cout<<endl;
        }
    }

    return 0;


}
