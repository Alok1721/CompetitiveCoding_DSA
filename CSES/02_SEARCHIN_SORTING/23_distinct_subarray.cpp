#include <bits/stdc++.h>
#define mod ((int)1e9+7)
using namespace std;


long long kDistinctSubarray(vector<long long>&nums,int k)
{
    int n=nums.size();
    int left=0;
    int right=0;
    unordered_map<long long,int> count;
    long long result=0;

    while(right<n)
    {
        count[nums[right]]++;
        while((int)count.size()>k)
        {
            count[nums[left]]--;
            if(count[nums[left]]==0)
                count.erase(nums[left]);
            left++;
        }
        result+=right-left+1;
        right++;
    }
    return result;
}


int main()
{
    int t;
    t=1;
    while(t--)
    {
       int n,k;
       cin>>n>>k;
       vector<long long > nums(n);
       for(int i=0;i<n;i++)
       {
        cin>>nums[i];
       }
       long long result=kDistinctSubarray(nums,k);
       cout<<result<<endl;
    }
    return 0;
}