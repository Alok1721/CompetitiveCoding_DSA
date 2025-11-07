#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> stalls(n);
    for(int i=0;i<n;i++)
        cin>>stalls[i];
    sort(stalls.begin(),stalls.end());
    int left=1,right=stalls[n-1]-stalls[0];
    int ans=0;
    while(left<=right)
    {
        int mid=(left+right)/2;
        int count=1;
        int last_position=stalls[0];
        for(int i=1;i<n;i++)
        {
            if(stalls[i]-last_position>=mid)
            {
                count++;
                last_position=stalls[i];
            }
        }
        if(count>=k)
        {
            ans=mid;
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}