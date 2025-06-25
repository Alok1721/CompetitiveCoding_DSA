#include<bits/stdc++.h>
using namespace std;
void find3Sum(vector<int>&v,vector<vector<int>>&result,int target)
{
    int n= v.size();
    sort(v.begin(), v.end());
    for(int i=0;i<n-2;i++)
    {
        if(i>0 && v[i]==v[i-1])continue;

        int left=i+1;
        int right=n-1;
        while(left<right)
        {
            int sum=v[i]+v[left]+v[right];
            if(sum==target)
            {
                result.push_back({v[i],v[left],v[right]});
                while(left<right && v[left]==v[left+1]) left++;
                while(left<right && v[right]==v[right-1])right--;
                left++;
                right--;
            }
            else if(sum<target)
            {
                left++;
            }else
            {
                right--;
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    int target;
    cin>>target;
    for(int i = 0; i < n; i++)
        cin >> v[i];
    vector<vector<int>> result;
    find3Sum(v, result,target);
    for(int i=0;i<result.size();i++)
    {
        cout<<"{";
        for(int j=0;j<result[i].size();j++)
        {
            cout<<result[i][j];
            if(j<result[i].size()-1)
            {
                cout<<",";
            }
        }
        cout<<"}"<<",";
    }
    cout<<endl;
    return 0;
}