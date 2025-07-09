#include <bits/stdc++.h>
#define mod ((int)1e9+7)
using namespace std;

int findLongestUniqueSong(vector<long long>&songs,int n)
{

    int maxE=1;
    unordered_set<long long> st;
    int l=0;
    for(int r=0;r<n;r++)
    {
        while(st.find(songs[r])!=st.end())
        {
            st.erase(songs[l]);
            l++;
        }
        st.insert(songs[r]);
        maxE=max(maxE,r-l+1);

    }
    
    return maxE;
}


int main()
{
    int t;
    t=1;
    while(t--)
    {
        long long n;
        cin>>n;
        vector<long long> songs(n);
        for(int i=0;i<n;i++)
        {

            cin>>songs[i];
        }
        cout<<findLongestUniqueSong(songs,n)<<endl;
       
    }
    return 0;
}